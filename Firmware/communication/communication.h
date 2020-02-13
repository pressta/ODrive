#ifndef COMMANDS_H
#define COMMANDS_H

// TODO: resolve assert
#define assert(expr)

#ifdef __cplusplus

#include <functional>
#include <limits>

extern "C" {
#endif

#include <cmsis_os.h>

extern osThreadId comm_thread;

extern const uint8_t hw_version_major;
extern const uint8_t hw_version_minor;
extern const uint8_t hw_version_variant;

void init_communication(void);
void communication_task(void * ctx);
void debug(const char *file, int line, const char *msg);

#define DEBUG(msg) debug(__FILE__, __LINE__, msg)

#ifdef __cplusplus
}
#endif

#endif /* COMMANDS_H */
