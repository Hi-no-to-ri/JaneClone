/*
 *    Copyright (c) <2002-2009> <Jean-Philippe Barrette-LaPierre>
 *    
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files 
 *    (curlpp), to deal in the Software without restriction, 
 *    including without limitation the rights to use, copy, modify, merge,
 *    publish, distribute, sublicense, and/or sell copies of the Software,
 *    and to permit persons to whom the Software is furnished to do so, 
 *    subject to the following conditions:
 *    
 *    The above copyright notice and this permission notice shall be included
 *    in all copies or substantial portions of the Software.
 *    
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 *    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 *    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 *    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef CURLPP_OPTIONS_HPP
#define CURLPP_OPTIONS_HPP


#include "Option.hpp"

#include <iostream> 


#ifdef CURLPP_ALLOW_NOT_AVAILABLE
#define DEF_IF_ALLOW_AVAILABLE (type,option,name) typedef curlpp::NotAvailableOptionTrait<type, option> name;
#endif

// #begin define OPTION(version,type,option,name) 
// #if LIBCURL_VERSION_NUM >= version 
//   typedef curlpp::OptionTrait<type, option> name;
// #else
// DEF_IF_ALLOW_AVAILABLE(type,option,name)
// #endif
// #end


namespace curlpp
{


namespace options
{


	/**
	* Cookie interface.
	*/

	#if LIBCURL_VERSION_NUM >= 0x070d01
		typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_COOKIELIST)> CookieList;
	#else
	#ifdef CURLPP_ALLOW_NOT_AVAILABLE
		typedef curlpp::NotAvailableOptionTrait<std::string> CookieList;
	#endif
	#endif

	/**
	* Behavior options.
	*/

	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_VERBOSE)> Verbose;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_HEADER)> Header;
	#if LIBCURL_VERSION_NUM >= 0x070A00
		typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_NOSIGNAL)> NoSignal;
	#else
	#ifdef CURLPP_ALLOW_NOT_AVAILABLE
		typedef curlpp::NotAvailableOptionTrait<bool> NoSignal;
	#endif // CURLPP_ALLOW_NOT_AVAILABLE
	#endif // LIBCURL_VERSION_NUM

	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_NOPROGRESS)> NoProgress;


	/**
	* Callback options. 
	*/

	typedef curlpp::OptionTrait<curl_write_callback, static_cast<CURLoption>(CURLOPT_WRITEFUNCTION)>
		WriteFunctionCurlFunction;

	typedef curlpp::OptionTrait<curlpp::types::WriteFunctionFunctor, static_cast<CURLoption>(CURLOPT_WRITEFUNCTION)>
		WriteFunction;


       /**
	* Using this option will reset CURLOPT_WRITEFUNCTION to 
	* default callback. In fact, use only this option if you only 
	* want libcURL to use the FILE * given in argument instead 
	* of stdout. 
	*/

	#if LIBCURL_VERSION_NUM >= 0x070907
		typedef curlpp::OptionTrait<FILE *, static_cast<CURLoption>(CURLOPT_WRITEDATA)> WriteFile;
		typedef curlpp::OptionTrait<std::ostream *, static_cast<CURLoption>(CURLOPT_WRITEDATA)> WriteStream;
	#else
	#ifdef CURLPP_ALLOW_NOT_AVAILABLE
		typedef curlpp::NotAvailableOptionTrait<FILE *, CURLOPT_WRITEDATA> WriteFile;
		typedef curlpp::NotAvailableOptionTrait<std::ostream *, CURLOPT_WRITEDATA> WriteStream;
	#endif // CURLPP_ALLOW_NOT_AVAILABLE
	#endif // LIBCURL_VERSION_NUM


	#if LIBCURL_VERSION_NUM >= 0x070c01

		typedef curlpp::OptionTrait<curl_read_callback, static_cast<CURLoption>(CURLOPT_READFUNCTION)>
			ReadFunctionCurlFunction;

		typedef curlpp::OptionTrait<curlpp::types::ReadFunctionFunctor, static_cast<CURLoption>(CURLOPT_READFUNCTION)>
			ReadFunction;

	#else

	#ifdef CURLPP_ALLOW_NOT_AVAILABLE

		typedef curlpp::NotAvailableOptionTrait<curl_read_callback, CURLOPT_READFUNCTION>
			ReadFunctionCurlFunction;

		typedef curlpp::NotAvailableOptionTrait<curlpp::types::ReadFunctionFunctor, CURLOPT_READFUNCTION>
			ReadFunction;

	#endif // CURLPP_ALLOW_NOT_AVAILABLE

	#endif // LIBCURL_VERSION_NUM


	/**
	* Using this option will reset CURLOPT_READFUNCTION to 
	* default callback. In fact, use only this option if you only 
	* want libcURL to use the FILE * given in argument instead 
	* of stdout. 
	*/

	#if LIBCURL_VERSION_NUM >= 0x070907
		typedef curlpp::OptionTrait<FILE *, static_cast<CURLoption>(CURLOPT_READDATA)> ReadFile;
		typedef curlpp::OptionTrait<std::istream *, static_cast<CURLoption>(CURLOPT_READDATA)> ReadStream;
	#else
	#ifdef CURLPP_ALLOW_NOT_AVAILABLE
		typedef curlpp::NotAvailableOptionTrait<FILE *, CURLOPT_READDATA> ReadFile;
		typedef curlpp::NotAvailableOptionTrait<std::istream *, CURLOPT_READDATA> ReadStream;
	#endif // CURLPP_ALLOW_NOT_AVAILABLE
	#endif // LIBCURL_VERSION_NUM

	typedef curlpp::OptionTrait<curlpp::types::ProgressFunctionFunctor, static_cast<CURLoption>(CURLOPT_PROGRESSFUNCTION)>
		ProgressFunction;

	typedef curlpp::OptionTrait<curlpp::types::WriteFunctionFunctor, static_cast<CURLoption>(CURLOPT_HEADERFUNCTION)>
		HeaderFunction;

	typedef curlpp::OptionTrait<curlpp::types::DebugFunctionFunctor, static_cast<CURLoption>(CURLOPT_DEBUGFUNCTION)>
		DebugFunction;

	typedef curlpp::OptionTrait<curlpp::types::SslCtxFunctionFunctor, static_cast<CURLoption>(CURLOPT_SSL_CTX_FUNCTION)>
		SslCtxFunction;

	/**
	* Error options.
	*/

	typedef curlpp::OptionTrait<char *, static_cast<CURLoption>(CURLOPT_ERRORBUFFER)> ErrorBuffer;

	#ifdef FILE
		typedef curlpp::OptionTrait<FILE *, static_cast<CURLoption>(CURLOPT_STDERR)> StdErr;
	#endif

	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FAILONERROR)> FailOnError;


	/**
	* Network options.
	*/

	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_URL)> Url;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_PROXY)> Proxy;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_PROXYPORT)> ProxyPort;
	typedef curlpp::OptionTrait<curl_proxytype, static_cast<CURLoption>(CURLOPT_PROXYTYPE)> ProxyType;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_HTTPPROXYTUNNEL)> HttpProxyTunnel;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_INTERFACE)> Interface;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_DNS_CACHE_TIMEOUT)> DnsCacheTimeout;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_DNS_USE_GLOBAL_CACHE)> DnsUseGlobalCache;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_BUFFERSIZE)> BufferSize;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_PORT)> Port;

	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_TCP_NODELAY)> TcpNoDelay;


	/**
	* Names and passwords options.
	*/

	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_NETRC)> Netrc;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_NETRC_FILE)> NetrcFile;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_USERPWD)> UserPwd;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_PROXYUSERPWD)> ProxyUserPwd;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_HTTPAUTH)> HttpAuth;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_PROXYAUTH)> ProxyAuth;


	/**
	* HTTP options.
	*/

	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_AUTOREFERER)> AutoReferer;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_ENCODING)> Encoding;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FOLLOWLOCATION)> FollowLocation;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_UNRESTRICTED_AUTH)> UnrestrictedAuth;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_MAXREDIRS)> MaxRedirs;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_PUT)> Put;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_UPLOAD)> Upload;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_POST)> Post;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_POSTFIELDS)> PostFields;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_POSTFIELDSIZE)> PostFieldSize;
	typedef curlpp::OptionTrait<curl_off_t, static_cast<CURLoption>(CURLOPT_POSTFIELDSIZE_LARGE)> PostFieldSizeLarge;
	typedef curlpp::OptionTrait<curlpp::Forms, static_cast<CURLoption>(CURLOPT_HTTPPOST)> HttpPost;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_REFERER)> Referer;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_USERAGENT)> UserAgent;
	typedef curlpp::OptionTrait<std::list<std::string>, CURLOPT_HTTPHEADER> HttpHeader;
	typedef curlpp::OptionTrait<std::list<std::string>, CURLOPT_HTTP200ALIASES> Http200Aliases;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_COOKIE)> Cookie;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_COOKIEFILE)> CookieFile;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_COOKIEJAR)> CookieJar;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_COOKIESESSION)> CookieSession;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_HTTPGET)> HttpGet;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_HTTP_VERSION)> HttpVersion;


	/**
	* FTP options.
	*/

	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_FTPPORT)> FtpPort;
	typedef curlpp::OptionTrait<std::list<std::string>, CURLOPT_QUOTE> Quote;
	typedef curlpp::OptionTrait<std::list<std::string>, CURLOPT_POSTQUOTE> PostQuote;
	typedef curlpp::OptionTrait<std::list<std::string>, CURLOPT_PREQUOTE> PreQuote;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FTPLISTONLY)> FtpListOnly;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FTPAPPEND)> FtpAppend;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FTP_USE_EPSV)> FtpUseEpsv;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_FTP_FILEMETHOD)> FtpFileMethod;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FTP_CREATE_MISSING_DIRS)> FtpCreateMissingDirs;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FTP_RESPONSE_TIMEOUT)> FtpResponseTimeout;
	typedef curlpp::OptionTrait<curl_ftpssl, static_cast<CURLoption>(CURLOPT_FTP_SSL)> FtpSsl;
	typedef curlpp::OptionTrait<curl_ftpauth, static_cast<CURLoption>(CURLOPT_FTPSSLAUTH)> FtpSslAuth;


	/**
	* Protocol options.
	*/

	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_TRANSFERTEXT)> TransferText;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_CRLF)> Crlf;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_RANGE)> Range;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_RESUME_FROM)> ResumeFrom;
	typedef curlpp::OptionTrait<curl_off_t, static_cast<CURLoption>(CURLOPT_RESUME_FROM_LARGE)> ResumeFromLarge;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_CUSTOMREQUEST)> CustomRequest;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FILETIME)> FileTime;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_NOBODY)> NoBody;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_INFILESIZE)> InfileSize;
	typedef curlpp::OptionTrait<curl_off_t, static_cast<CURLoption>(CURLOPT_INFILESIZE_LARGE)> InfileSizeLarge;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_MAXFILESIZE)> MaxFileSize;
	typedef curlpp::OptionTrait<curl_off_t, static_cast<CURLoption>(CURLOPT_MAXFILESIZE_LARGE)> MaxFileSizeLarge;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_TIMECONDITION)> TimeCondition;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_TIMEVALUE)> TimeValue;


	/**
	* Connection options.
	*/

	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_TIMEOUT)> Timeout;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_LOW_SPEED_LIMIT)> LowSpeedLimit;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_LOW_SPEED_TIME)> LowSpeedTime;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_MAXCONNECTS)> MaxConnects;
	typedef curlpp::OptionTrait<curl_closepolicy, static_cast<CURLoption>(CURLOPT_CLOSEPOLICY)> ClosePolicy;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FRESH_CONNECT)> FreshConnect;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_FORBID_REUSE)> ForbidReuse;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_CONNECTTIMEOUT)> ConnectTimeout;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_IPRESOLVE)> IpResolve;


	/**
	* SSL and security options.
	*/

	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSLCERT)> SslCert;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSLCERTTYPE)> SslCertType;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSLCERTPASSWD)> SslCertPasswd;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSLKEY)> SslKey;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSLKEYTYPE)> SslKeyType;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSLKEYPASSWD)> SslKeyPasswd;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSLENGINE)> SslEngine;
	typedef curlpp::NoValueOptionTrait<CURLOPT_SSLENGINE_DEFAULT> SslEngineDefault;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_SSLVERSION)> SslVersion;
	typedef curlpp::OptionTrait<bool, static_cast<CURLoption>(CURLOPT_SSL_VERIFYPEER)> SslVerifyPeer;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_CAINFO)> CaInfo;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_CAPATH)> CaPath;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_RANDOM_FILE)> RandomFile;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_EGDSOCKET)> EgdSocket;
	typedef curlpp::OptionTrait<long, static_cast<CURLoption>(CURLOPT_SSL_VERIFYHOST)> SslVerifyHost;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_SSL_CIPHER_LIST)> SslCipherList;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_KRB4LEVEL)> Krb4Level;


	/**
	* Other options.
	*/

	typedef curlpp::OptionTrait<void *, static_cast<CURLoption>(CURLOPT_PRIVATE)> Private;
	typedef curlpp::OptionTrait<std::string, static_cast<CURLoption>(CURLOPT_KRB4LEVEL)> Krb4Level;


	//Share;
	//TelnetOptions


} // namespace options

	namespace Options = options;


} // namespace curlpp

namespace cURLpp = curlpp;


std::ostream & operator<<(std::ostream & stream, const curlpp::options::Url & url);


#endif // #ifndef CURLPP_OPTIONS_HPP
