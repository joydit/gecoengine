#include "profile_t.h"

uint64 runningTime()
{
	return Profiles::instance_ptr()->runningTime();
}

Profiles::Profiles(std::string name) : name_(name)
{
	stamps_per_sec();
	Profile* pRunningTime = new Profile("RunningTime", this);
	pRunningTime->start();
}
Profiles::~Profiles()
{
	delete this->pRunningTime();
}
bool Profiles::initializeWatcher()
{
	return true;
}
time_stamp_t Profiles::runningTime() const
{
	return time_stamp_t() - this->pRunningTime()->lastTime_;
}
void Profiles::add(Profile * pVal)
{
	profiles_.push_back(pVal);
}
///////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////
time_stamp_t Profile::warningPeriod_(stamps_per_sec() / 100); // 10ms
Profile::Profile(std::string name, Profiles* profiles) :
	strName_(name),
	pProfiles_(profiles),
	lastTime_(0),
	sumTime_(0),
	lastInternalTime_(0),
	sumInternalTime_(0),
	lastVal2Stop_(0),
	sumAllVals2Stop_(0),
	stopCounts_(0),
	inProgress_(0),
	initWatcher_(false)
{
	if (pProfiles_ == NULL)
	{
		pProfiles_ = new Profiles("default profiles");
	}

	if (!strName_.empty())
	{
		pProfiles_->add(this);
	}
}
Profile::~Profile()
{
	if (pProfiles_)
	{
		// pProfileGroup_.erase(std::remove( pProfileGroup_->begin(), pProfileGroup_->end(), this ), pProfileGroup_->end());
	}
}
void Profile::start(void)
{
	//TRACE("Profile::start()");

	if (!initWatcher_ && stopCounts_ > 10)
	{
		initializeWatcher();
	}

	time_stamp_t now = time_stamp_t();

	// ��¼�ڼ��δ���
	if (inProgress_++ == 0)
	{
		lastTime_ = now;
	}

	Profiles::ProfilesType& stack = pProfiles_->stack_;
	if (!stack.empty())
	{
		Profile* profile = stack.back();
		profile->lastInternalTime_ = now - profile->lastInternalTime_;
		profile->sumInternalTime_ += profile->lastInternalTime_;
	}

	stack.push_back(this);
	lastInternalTime_ = now;

	//TRACE_RETURN_VOID();
}
void Profile::stop(uint32 qty)
{
	//TRACE("Profile::stop()");

	time_stamp_t now = time_stamp_t();

	/// ���Ϊ0������Լ��ǵ���ջ�Ĳ����� �ڴ����ǿ��Եõ���������ܹ��ķѵ�ʱ��
	if (--inProgress_ == 0)
	{
		lastTime_ = now - lastTime_;
		sumTime_ += lastTime_;
	}

	lastVal2Stop_ = qty;
	sumAllVals2Stop_ += qty;
	++stopCounts_;

	Profiles::ProfilesType& stack = pProfiles_->stack_;
	stack.pop_back();

	// �õ��������������ķѵ�ʱ��
	lastInternalTime_ = now - lastInternalTime_;
	sumInternalTime_ += lastInternalTime_;

	// ������Ҫ�ڴ�������һ�������е�profile��������һ���ڲ�ʱ��
	// ʹ���ܹ���startʱ��ȷ�õ��Ե����걾����֮�������һ��profile������ʱ������
	// ��ʱ��Ƭ��
	if (!stack.empty())
		stack.back()->lastInternalTime_ = now;

	//TRACE_RETURN_VOID();
}