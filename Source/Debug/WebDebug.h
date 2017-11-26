#ifndef DEBUG_WEBDEBUG_H_
#define DEBUG_WEBDEBUG_H_

#include <string>
#include <vector>

#include "absl/strings/str_split.h"
#include "System/DataSink.h"

struct WebbyConnection;

class WebDebugConnection : public DataSink
{
   public:
	explicit WebDebugConnection(WebbyConnection* connection);

	enum State
	{
		kUnresponded,
		kResponding,
		kResponded,
	};

	struct Param
	{
		std::string Key;
		std::string Value;
	};

	typedef std::vector<Param> QueryParams;

	const char* GetQueryString() const;
	State GetState() const { return mState; }

	const QueryParams& GetQueryParams() const { return mQueryParams; }

	void BeginResponse(int code, int content_length, const char* content_type);
	void EndResponse();

	void WriteString(const char* str);
	void WriteF(const char* format, ...);

	// DataSink interface
	virtual size_t Write(const void* p, size_t len);
	virtual void Flush();

   private:
	WebbyConnection* mConnection;
	State mState;

	size_t mBytesExpected;
	size_t mBytesWritten;

	QueryParams mQueryParams;
};

extern const char* const kApplicationJavascript;
extern const char* const kApplicationJSON;
extern const char* const kImagePng;
extern const char* const kTextCSS;
extern const char* const kTextHTML;
extern const char* const kTextPlain;

bool ServeResource(WebDebugConnection* connection, const char* resource_path);
void Generate404(WebDebugConnection* connection, const char* request);
void Generate500(WebDebugConnection* connection, const char* message);

class WebDebugHandler {
  public:
	virtual ~WebDebugHandler();

	virtual void HandleRequest(WebDebugConnection* connection) = 0;
};

void WebDebug_Register(const char* request, WebDebugHandler* handler);

bool WebDebug_Init();
void WebDebug_Fini();

#endif  // DEBUG_WEBDEBUG_H_
