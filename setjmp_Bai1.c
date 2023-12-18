#include <setjmp.h>

static char error_message[1024];

void THROW(int error_code, const char *error_message) {
  strcpy(error_message, error_message);
  longjmp(env, error_code);
}
double divide(int a, int b) {
  if (b == 0) {
    THROW(1, "Lỗi: Phép chia cho 0!");
  }
  return (double)a / b;
}
int main() {
  double x = divide(10, 0);

  CATCH(1) {
    printf("%s\n", error_message);
  }
  CATCH(2) {
    printf("%s\n", error_message);
  }

  return 0;
}
