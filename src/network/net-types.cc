#include "net-types.h"
//#include "GecoWatcher.h"

#ifdef _WIN32
#ifndef _XBOX360
#include <Winsock.h>
#endif
#elif defined( PLAYSTATION3 )
#include <netinet/in.h>
#else
#include <arpa/inet.h>
#endif

extern std::shared_ptr<spdlog::logger> geco_network_console_logger = spdlog::stdout_color_mt("geco-network-console-logger");
// Create a file rotating logger with 5mb size max and 3 rotated files
extern std::shared_ptr<spdlog::logger> geco_network_daily_logger =
spdlog::rotating_logger_mt("geco-network-daily_logger", "logs/geco-network-daily_log", 1048576 * 5, 3);

char GecoNetAddress::ms_pcStringBuf[2][GecoNetAddress::MAX_STRLEN];
int GecoNetAddress::ms_iCurrStringBuf = 0;
const GecoNetAddress GecoNetAddress::NONE(0, 0);

bool WatcherStringToValue(const char * valueStr, GecoNetAddress & value)
{
	int a1, a2, a3, a4, a5;

	if (sscanf(valueStr, "%d.%d.%d.%d:%d",
		&a1, &a2, &a3, &a4, &a5) != 5)
	{
		//FV_WARNING_MSG("WatcherStringToValue: "
		//	"Cannot convert '%s' to an Address.\n", valueStr);
		return false;
	}

	value.m_uiIP = (a1 << 24) | (a2 << 16) | (a3 << 8) | a4;

	value.m_uiPort = ushort(a5);
	value.m_uiPort = ntohs(value.m_uiPort);
	value.m_uiIP = ntohl(value.m_uiIP);

	return true;
}

GecoNetAddress::GecoNetAddress(char* str)
	:m_uiIP(0)
	, m_uiPort(0)
	, m_uiSalt(0)
{
	SetFromString(str);
}

int GecoNetAddress::WriteToString(char * str, int length) const
{
	uint	hip = ntohl(m_uiIP);
	ushort	hport = ntohs(m_uiPort);

	return geco_snprintf(str, length,
		"%d.%d.%d.%d:%d",
		(int)(unsigned char)(hip >> 24),
		(int)(unsigned char)(hip >> 16),
		(int)(unsigned char)(hip >> 8),
		(int)(unsigned char)(hip),
		(int)hport);
}

char * GecoNetAddress::c_str() const
{
	char * buf = GecoNetAddress::NextStringBuf();
	this->WriteToString(buf, MAX_STRLEN);
	return buf;
}

const char * GecoNetAddress::IPAsString() const
{
	uint	hip = ntohl(m_uiIP);
	char * buf = GecoNetAddress::NextStringBuf();

	geco_snprintf(buf, MAX_STRLEN,
		"%d.%d.%d.%d",
		(int)(unsigned char)(hip >> 24),
		(int)(unsigned char)(hip >> 16),
		(int)(unsigned char)(hip >> 8),
		(int)(unsigned char)(hip));

	return buf;
}

bool GecoNetAddress::SetFromString(char* str)
{
	if (!str)
		return false;

	int a1, a2, a3, a4, a5;

	if (sscanf(str, "%d.%d.%d.%d:%d",
		&a1, &a2, &a3, &a4, &a5) != 5)
		return false;

	m_uiIP = (a1 << 24) | (a2 << 16) | (a3 << 8) | a4;

	m_uiPort = ushort(a5);
	m_uiPort = ntohs(m_uiPort);
	m_uiIP = ntohl(m_uiIP);

	return true;
}

#if FV_ENABLE_WATCHERS
GecoWatcher & GecoNetAddress::GetWatcher()
{
	static GecoMemberWatcher<char *, GecoNetAddress>	* watchMe = NULL;

	if (watchMe == NULL)
	{
		watchMe = new GecoMemberWatcher<char *, GecoNetAddress>(
			*((GecoNetAddress*)NULL),
			&GecoNetAddress::operator char*,
			static_cast<void (GecoNetAddress::*)(char*)>(NULL)
			);
	}

	return *watchMe;
}
#endif // FV_ENABLE_WATCHERS


char * GecoNetAddress::NextStringBuf()
{
	ms_iCurrStringBuf = (ms_iCurrStringBuf + 1) % 2;
	return ms_pcStringBuf[ms_iCurrStringBuf];
}


