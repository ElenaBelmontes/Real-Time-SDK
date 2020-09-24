/*|-----------------------------------------------------------------------------
*|            This source code is provided under the Apache 2.0 license      --
*|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
*|                See the project's LICENSE.md for details.                  --
*|           Copyright (C) 2019 Refinitiv. All rights reserved.            --
*|-----------------------------------------------------------------------------
*/

#ifndef __rtsdk_ema_domain_LoginReqImpl_h
#define __rtsdk_ema_domain_LoginReqImpl_h

#include "ElementList.h"
#include "EmaBuffer.h"
#include "EmaString.h"
#include "ReqMsg.h"
#include "ExceptionTranslator.h"

namespace rtsdk {

namespace ema {

namespace domain {

namespace login {

class LoginReqImpl
{
public:

	LoginReqImpl();

	LoginReqImpl(const LoginReqImpl&);

	LoginReqImpl(const rtsdk::ema::access::ReqMsg&);

	virtual ~LoginReqImpl();

	LoginReqImpl& clear();

	LoginReqImpl& operator=(const LoginReqImpl&);

	LoginReqImpl& message(const rtsdk::ema::access::ReqMsg&);

	LoginReqImpl& allowSuspectData(bool value);

	LoginReqImpl& downloadConnectionConfig(bool value);

	LoginReqImpl& applicationId(const rtsdk::ema::access::EmaString&);

	LoginReqImpl& applicationName(const rtsdk::ema::access::EmaString&);

	LoginReqImpl& applicationAuthorizationToken(const rtsdk::ema::access::EmaString&);

	LoginReqImpl& instanceId(const rtsdk::ema::access::EmaString&);

	LoginReqImpl& password(const rtsdk::ema::access::EmaString&);

	LoginReqImpl& position(const rtsdk::ema::access::EmaString&);

	LoginReqImpl& providePermissionExpressions(bool value);

	LoginReqImpl& providePermissionProfile(bool value);

	LoginReqImpl& role(rtsdk::ema::access::UInt32 value);

	LoginReqImpl& singleOpen(bool value);

	LoginReqImpl& supportProviderDictionaryDownload(bool value);

	LoginReqImpl& pause(bool value);

	LoginReqImpl& authenticationExtended(const rtsdk::ema::access::EmaBuffer&);

	LoginReqImpl& name(const rtsdk::ema::access::EmaString&);

	LoginReqImpl& nameType(const rtsdk::ema::access::UInt32&);

	bool hasAllowSuspectData() const;

	bool hasDownloadConnectionConfig() const;

	bool hasApplicationId() const;

	bool hasApplicationName() const;

	bool hasApplicationAuthorizationToken() const;

	bool hasInstanceId() const;

	bool hasPassword() const;

	bool hasPosition() const;

	bool hasProvidePermissionExpressions() const;

	bool hasProvidePermissionProfile() const;

	bool hasRole() const;

	bool hasSingleOpen() const;

	bool hasSupportProviderDictionaryDownload() const;

	bool hasPause() const;

	bool hasAuthenticationExtended() const;

	bool hasName() const;

	bool hasNameType() const;

	bool getAllowSuspectData() const;

	bool getDownloadConnectionConfig() const;

	const rtsdk::ema::access::ReqMsg& getMessage();

	const rtsdk::ema::access::EmaString& getApplicationId() const;

	const rtsdk::ema::access::EmaString& getApplicationName() const;

	const rtsdk::ema::access::EmaString& getApplicationAuthorizationToken() const;

	const rtsdk::ema::access::EmaString& getInstanceId() const;

	const rtsdk::ema::access::EmaString& getPassword() const;

	const rtsdk::ema::access::EmaString& getPosition() const;

	bool getProvidePermissionExpressions() const;

	bool getProvidePermissionProfile() const;

	rtsdk::ema::access::UInt32 getRole() const;

	bool getSingleOpen() const;

	bool getSupportProviderDictionaryDownload() const;

	bool getPause() const;

	const rtsdk::ema::access::EmaBuffer& getAuthenticationExtended() const;

	const rtsdk::ema::access::EmaString& getName() const;

	const rtsdk::ema::access::UInt32& getNameType() const;

	const rtsdk::ema::access::EmaString& toString() const;

private:

	void encode(rtsdk::ema::access::ReqMsg&) const;

	void decode(const rtsdk::ema::access::ReqMsg&);

	const rtsdk::ema::access::ReqMsg& message() const;

	bool								    _allowSuspectData;
	bool								    _downloadConnectionConfig;
	bool									_providePermissionProfile;
	bool									_providePermissionExpressions;
	bool						            _singleOpen;
	bool									_supportProviderDictionaryDownload;
	rtsdk::ema::access::UInt32									_role;
	bool									_pause;
	rtsdk::ema::access::EmaString	                            _applicationId;
	rtsdk::ema::access::EmaString	                            _applicationName;
	rtsdk::ema::access::EmaString	                            _applicationAuthToken;
	rtsdk::ema::access::EmaString	                            _instanceId;
	rtsdk::ema::access::EmaString	                            _password;
	rtsdk::ema::access::EmaString	                            _position;
	rtsdk::ema::access::EmaString								_authenticationToken;
	rtsdk::ema::access::EmaBuffer								_authenticationExtended;

	mutable bool		                    _changed;
	bool		                            _allowSuspectDataSet;
	bool		                            _downloadConnectionConfigSet;
	bool		                            _providePermissionProfileSet;
	bool		                            _providePermissionExpressionsSet;
	bool		                            _singleOpenSet;
	bool		                            _supportProviderDictionaryDownloadSet;
	bool		                            _roleSet;
	bool									_pauseSet;
	bool		                            _applicationIdSet;
	bool		                            _applicationNameSet;
	bool		                            _applicationAuthTokenSet;
	bool		                            _instanceIdSet;
	bool		                            _passwordSet;
	bool		                            _positionSet;
	bool									_authenticationExtendedSet;
	bool									_nameSet;
	bool									_nameTypeSet;

	mutable rtsdk::ema::access::ElementList*	                _pElementList;

	rtsdk::ema::access::UInt32									_domainType;
	rtsdk::ema::access::UInt32									_nameType;
	rtsdk::ema::access::EmaString								_name;
	
	rtsdk::ema::access::EmaString						_defaultName;
	rtsdk::ema::access::EmaString						_defaultPosition;

	rtsdk::ema::access::ReqMsg									_reqMsg;

	mutable rtsdk::ema::access::EmaString                       _toString;

	char																defaultUsername[256];
	char																defaultPosition[256];
};

}

}

}

}

#endif // __rtsdk_ema_domain_LoginReqImpl_h
