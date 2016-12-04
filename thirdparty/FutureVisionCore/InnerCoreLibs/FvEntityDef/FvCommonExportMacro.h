//{future header message}
#ifndef __FvCommonExportMacro_H__
#define __FvCommonExportMacro_H__



//! ���� FvObjMailBox��GlobalMB�ӿ�
#if defined(FV_BASE) || defined(FV_CELL)

#define FVMAILBOX_GLOBALMAILBOX_DECLARE(_MAILBOX)				\
	static const _MAILBOX& GlobalMB()							\
	{															\
		return _MAILBOX::GlobalMB(g_k##_MAILBOX##GlobalLabel);	\
	}															\
	static const _MAILBOX& GlobalMB(const FvString& kLabel);

#else

#define FVMAILBOX_GLOBALMAILBOX_DECLARE(_MAILBOX)

#endif



//! ���� FvObjMailBox�����ͺ�Castת���ӿ�
#define FVMAILBOX_TYPE_AND_CAST(_MAILBOX, _TYPE)								\
	static FvUInt16 GetEntityType() { return FvUInt16(_TYPE); }					\
	static const _MAILBOX* Cast(const FvMailBox* pkMailBox)						\
	{																			\
		if(!pkMailBox || pkMailBox->GetEntityType()!=0 && pkMailBox->GetEntityType()!=_MAILBOX::GetEntityType())\
		{																		\
			FV_ASSERT(0 && "FvMailBoxCast Type Err!");							\
			return NULL;														\
		}																		\
		else																	\
		{																		\
			return static_cast<const _MAILBOX*>(pkMailBox);						\
		}																		\
	}



//! ���� FvObjStruct����
#ifdef FV_SERVER

#define STRUCT_DECLARE(_STRUCTNAME)																		\
protected:																								\
	friend class FvObjStruct;																			\
	template<class, class> friend class FvObjArray;														\
	void EqualTo(const _STRUCTNAME##Obj& kRight);														\
	virtual void GetStructAddr(FvUInt32& uiCnt, NameAddr*& pkInfo) const;								\
	virtual bool GetPtToID(FvUInt32& uiCnt, FvUInt32*& pBits, FvUInt16*& pIdx, PtIdxToID*& pIDs) const;	\
	virtual bool GetIDToAddr(FvUInt32& uiCnt, FvUInt32*& pAddr) const;									\
public:																									\
	_STRUCTNAME##Obj():FvObjStruct() {}																	\
	_STRUCTNAME##Obj(const _STRUCTNAME& src);															\
	_STRUCTNAME##Obj(const _STRUCTNAME##Obj& src);														\
	_STRUCTNAME##Obj& operator=(const _STRUCTNAME& src);												\
	_STRUCTNAME##Obj& operator=(const _STRUCTNAME##Obj& src);											\
	operator _STRUCTNAME() const;

#else

#define STRUCT_DECLARE(_STRUCTNAME)																		\
protected:																								\
	virtual void GetStructAddr(FvUInt32& uiCnt, NameAddr*& pkInfo) const;								\
	virtual bool GetPtToID(FvUInt32& uiCnt, FvUInt32*& pBits, FvUInt16*& pIdx, PtIdxToID*& pIDs) const;	\
	virtual bool GetIDToAddr(FvUInt32& uiCnt, FvUInt32*& pAddr) const;									\
	_STRUCTNAME##Obj& operator=(const _STRUCTNAME& src);												\
	_STRUCTNAME##Obj& operator=(const _STRUCTNAME##Obj& src);											\
public:																									\
	_STRUCTNAME##Obj():FvObjStruct() {}																	\
	_STRUCTNAME##Obj(const _STRUCTNAME& src);															\
	_STRUCTNAME##Obj(const _STRUCTNAME##Obj& src);														\
	operator _STRUCTNAME() const;

#endif



//! ���� FvObjUDO����
#define UDO_DECLARE(_NAME, _ID)										\
	_NAME();														\
	virtual ~_NAME() {}												\
	static FvUInt16	UDOType() { return _ID; }						\
	virtual FvUInt16 GetUDOType() const { return _ID; }				\
	virtual	bool DeserializeFromSection(FvXMLSectionPtr spSection)



//! ����������ֵ��������
#define  NUM_FIXARRAY_DECLARE\
	virtual const char** GetItemName() const;



//! ���� FvAllData����
#define ALLDATA_DECLARE(_CLASS, _TYPE)								\
	_CLASS##AllData();												\
	virtual FvUInt16 GetType() const { return FvUInt16(_TYPE); }	\
	virtual bool SerializeToStream(FvBinaryOStream& kOS) const;		\
	virtual	bool DeserializeFromSection(FvXMLSectionPtr spSection);



//! ���� ClientEntity����
#define CLIENTENTITY_EXPORT_DECLARE(_CLASS)	\
	friend FvEntity* EntityCreateFunc_of_##_CLASS();



//! ���� BaseEntity����
#define BASEENTITY_EXPORT_DECLARE(_CLASS)										\
	friend FvEntity* EntityCreateFunc_of_##_CLASS();							\
	virtual void InitAttrib(const FvAllData* pkAllData, FvCellData* pkCellData);\
	virtual void InitAttribNoDBData();											\
	virtual void CopyAttrib(FvAllData* pkAllData, FvCellData* pkCellData);



//! ���� CellEntity����
#define CELLENTITY_EXPORT_DECLARE(_CLASS)										\
	friend FvEntity* EntityCreateFunc_of_##_CLASS();							\
	virtual void InitAttrib(const FvAllData* pkAllData);



//! ���� GlobalEntity����
#define GLOBALENTITY_EXPORT_DECLARE(_CLASS)	\
	friend FvEntity* EntityCreateFunc_of_##_CLASS();



//! ���� ClientEntity����ľ���
#define DEFINE_CLIENTENTITY_MIRROR_START(_CLASS, _PARENT)	\
	struct ClientEntityMirror_of_##_CLASS : public _PARENT	\
	{

#define CLIENT_MIRROR_MEMBER(_MEMBER)	char* m_##_MEMBER;

#define DEFINE_CLIENTENTITY_MIRROR_END	};



//! ���� BaseEntity����ľ���
#define DEFINE_BASEENTITY_MIRROR_START(_CLASS, _PARENT)	\
	struct BaseEntityMirror_of_##_CLASS : public _PARENT\
	{

#define BASE_MIRROR_MEMBER(_TYPE, _MEMBER)	_TYPE m_##_MEMBER;

#define DEFINE_BASEENTITY_MIRROR_END	};



//! ���� CellData����
#define CELLDATA_DECLARE(_CLASS, _PARENT)											\
	_CLASS##CellData():_PARENT() {}													\
	protected:																		\
	virtual void InitDefaultValForNoDBData();										\
	virtual bool SerializeToStreamByIdx(FvUInt16 uiIdx, FvBinaryOStream& kOS) const;\
	virtual bool SerializeToStreamForDBData(FvBinaryOStream& kOS) const;			\
	virtual bool SerializeToStreamForAllData(FvBinaryOStream& kOS) const;			\
	virtual bool DeserializeFromStreamByIdx(FvUInt16 uiIdx, FvBinaryIStream& kIS);	\
	virtual bool DeserializeFromStreamForDBData(FvBinaryIStream& kIS);				\
	virtual bool DeserializeFromStreamForAllData(FvBinaryIStream& kIS);



//! ���� CellEntity����ľ���
#define DEFINE_CELLENTITY_MIRROR_START(_CLASS, _PARENT)	\
	struct CellEntityMirror_of_##_CLASS : public _PARENT\
	{

#define MIRROR_MEMBER(_TYPE, _MEMBER)		_TYPE	m_##_MEMBER;
#define MIRROR_MEMBER_REF(_TYPE, _MEMBER)	_TYPE*	m_##_MEMBER;

#define DEFINE_CELLENTITY_MIRROR_END	};



//! ���� Dll�ĵ���
#define DEFINE_DLL_EXPORT_START(_PREFIX, _PART_, MD5_DIGEST)										\
	static FvAll##_PART_##EntityExports s_kAllEntityExports;										\
	static Fv##_PART_##EntityExport* s_ppkEntityExportArray[_PREFIX##EntityType::MAX ? _PREFIX##EntityType::MAX : 1];\
	void DllExport(FvAll##_PART_##EntityExports*& pkEntityExports)									\
	{																								\
		pkEntityExports = &s_kAllEntityExports;														\
																									\
		s_kAllEntityExports.kMD5Digest.Unquote(MD5_DIGEST);											\
		s_kAllEntityExports.uiEntityCnt = _PREFIX##EntityType::MAX;									\
		memset(s_ppkEntityExportArray, 0, sizeof(s_ppkEntityExportArray)/sizeof(s_ppkEntityExportArray[0]));\
		s_kAllEntityExports.ppkEntityExport = s_ppkEntityExportArray;

#define DLL_EXPORT_ENTITY(_CLASS, _TYPE)							\
	extern void EntityExport_of_##_CLASS(void*&);					\
	EntityExport_of_##_CLASS((void*&)s_ppkEntityExportArray[_TYPE]);

#define DLL_EXPORT_STRUCT(_STRUCT)					\
	extern void StructExport_of_##_STRUCT##Obj();	\
	StructExport_of_##_STRUCT##Obj();

#define DLL_EXPORT_UDO								\
	extern void UDOExportFunc(AllUDOExports*&);		\
	UDOExportFunc(s_kAllEntityExports.pkUDOExports);

#define DLL_EXPORT_COMMON_MACROCMD(_PREFIX)										\
	extern _PREFIX void CommonMacroCmdExportFunc(LocalCallFuncByStrHandlerMap&);\
	CommonMacroCmdExportFunc(s_kAllEntityExports.kMacroCommandMap);

#define DLL_EXPORT_MACROCMD											\
	extern void MacroCmdExportFunc(LocalCallFuncByStrHandlerMap&);	\
	MacroCmdExportFunc(s_kAllEntityExports.kMacroCommandMap);

#define DEFINE_DLL_EXPORT_END	}



//! ���� FvDataPrint���ػ�
#define DATAPRINT_SPECIALIZE(_CLASS)									\
	namespace FvDataPrint												\
	{																	\
		template<>														\
		void FvDataPrint::Print(const char*, const _CLASS&, FvString&);	\
		template<>														\
		void FvDataPrint::Print(const _CLASS&, FvString&);				\
	}



//! �����д������Ե�ģ��
#define DEFINE_ENTITY_PACK_PROPERTY_GET_SET_TEMPLATE							\
	template<class T>															\
	bool GetPackPropertyValue(const FvUInt32 uiIdx, T& kValue) const			\
	{																			\
		const FvDataObj* pkObj = GetPackProperty(uiIdx);						\
		if(pkObj == NULL)														\
		{																		\
			return false;														\
		}																		\
		return pkObj->GetDataValue<T>(kValue);									\
	}																			\
	template<class T>															\
	const T PackPropertyValue(const FvUInt32 uiIdx, const T& kDefaultValue) const\
	{																			\
		const FvDataObj* pkObj = GetPackProperty(uiIdx);						\
		if(pkObj == NULL)														\
		{																		\
			return kDefaultValue;												\
		}																		\
		return pkObj->DataValue<T>(kDefaultValue);								\
	}																			\
	template<class T>															\
	bool SetPackPropertyValue(const FvUInt32 uiIdx, const T& kValue)			\
	{																			\
		FvDataObj* pkObj = GetPackProperty(uiIdx);								\
		if(pkObj == NULL)														\
		{																		\
			return false;														\
		}																		\
		return pkObj->SetDataValue<T>(kValue);									\
	}																			\
	virtual FvDataObj* GetPackProperty(FvUInt32 uiIdx) const;



#define INTERFACE_FRIEND_DECLARE(_PREFIX, _CLASS)				\
	friend class I##_CLASS;										\
	friend class _CLASS;										\
	friend FvEntity* EntityCreateFunc_of_##_CLASS();			\
	friend _PREFIX void EntityExport_of_##_CLASS(void*&);		\
	friend _PREFIX void EntityMethodsEntry_of_##_CLASS(FvEntity*, FvUInt16, FvBinaryIStream&)



#define ENTITY_DYNAMICCAST_DEFINE(_PREFIX, _CLASS, _TYPEID)					\
	static _CLASS* _CLASS::DynamicCast(FvEntity* pkEntity)					\
	{																		\
		if(pkEntity && pkEntity->GetEntityTypeID() == _PREFIX##EntityType::_TYPEID)\
			return static_cast<_CLASS*>(pkEntity);							\
		else																\
			return NULL;													\
	}																		\
	static _CLASS* _CLASS::DynamicCast(FvEntity& kEntity)					\
	{																		\
		if(kEntity.GetEntityTypeID() == _PREFIX##EntityType::_TYPEID)		\
			return static_cast<_CLASS*>(&kEntity);							\
		else																\
			return NULL;													\
	}																		\
	static bool _CLASS::IsType(FvEntity* pkEntity)							\
	{																		\
		if(pkEntity && pkEntity->GetEntityTypeID() == _PREFIX##EntityType::_TYPEID)\
			return true;													\
		else																\
			return false;													\
	}																		\
	static bool _CLASS::IsType(FvEntity& kEntity)							\
	{																		\
		if(kEntity.GetEntityTypeID() == _PREFIX##EntityType::_TYPEID)		\
			return true;													\
		else																\
			return false;													\
	}



#endif//__FvCommonExportMacro_H__

