#ifndef COMMANDS_H
#define COMMANDS_H

// TODO: resolve assert
#define assert(expr)

#ifdef __cplusplus

#include <functional>
#include <limits>


// XXX: rename this class
class DebugToken {
public:
  static void debug(const char *prefix);
  static void debug(const char *prefix, bool value);
  static void debug(const char *prefix, char value);
  static void debug(const char *prefix, const char *value);
  static void debug(const char *prefix, int value);
  static void debug(const char *prefix, unsigned int value);
  static void debug(const char *prefix, float value);

  // Handles sending debug messages
  static void loop();

  // Handles initializing debug context.
  static void init();

private:
  DebugToken() = delete;
};


#define DEBUG(prefix, ...) DebugToken::debug(prefix, ##__VA_ARGS__)
#define TRACE() DEBUG("trace: " __FILE__, __LINE__);


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
