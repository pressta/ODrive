#ifndef COMMANDS_H
#define COMMANDS_H

// TODO: resolve assert
#define assert(expr)

#ifdef __cplusplus

#include <functional>
#include <limits>


// A debug token is a handle to a partial debug message.
class DebugToken {
public:
  // You obtain a debug token via this static method
  static DebugToken begin(const char *file, int line);

  // You append values via std::ostream-style << operator chaining.
  DebugToken &operator<< (char value);
  // *** Be especially careful here: do not pass a pointer to a
  // stack-allocated string! ***
  DebugToken &operator<< (const char *value);
  DebugToken &operator<< (int value);
  DebugToken &operator<< (unsigned int value);
  DebugToken &operator<< (float value);

  // And the message is written when the token goes out of scope.
  ~DebugToken();

  // Handles sending debug messages
  static void loop();

  // Handles initializing debug context.
  static void init();

private:
  // A token just wraps some opaque id.
  void *id;

  // To keep things sane, the constructor is private. You can only
  // obtain a token via DebugToken::begin().
  DebugToken(void *id) : id(id) {}

  // Internal helper function.
  template <typename T> DebugToken &debug_impl(T callable);
};


#define DEBUG() DebugToken::begin(__FILE__, __LINE__)


extern "C" {
#endif

#include <cmsis_os.h>

extern osThreadId comm_thread;

extern const uint8_t hw_version_major;
extern const uint8_t hw_version_minor;
extern const uint8_t hw_version_variant;

void init_communication(void);
void communication_task(void * ctx);


#ifdef __cplusplus
}
#endif

#endif /* COMMANDS_H */
