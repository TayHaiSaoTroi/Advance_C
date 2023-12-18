#include <stdio.h>

enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR };

#define TRY {
#define CATCH(error_code) } else if (error_code == error_type) {
#define THROW(error_type, error_message) do { \
    error_code = error_type; \
    error_message = error_message; \
    goto end; \
} while (0)

static int error_code = NO_ERROR;
static char *error_message = NULL;
void readFile() {
  printf("Đọc file...\n");
  THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
  printf("Thực hiện thao tác mạng...\n");
  THROW(NETWORK_ERROR, "Lỗi thao tác mạng: Không thể kết nối đến máy chủ.");
}

void calculateData() {
  printf("Tính toán dữ liệu...\n");
  THROW(CALCULATION_ERROR, "Lỗi tính toán dữ liệu: Dữ liệu không hợp lệ.");
}
int main() {
  TRY {
    readFile();
    networkOperation();
    calculateData();
  } CATCH(FILE_ERROR) {
    printf("Lỗi đọc file: %s\n", error_message);
  } CATCH(NETWORK_ERROR) {
    printf("Lỗi thao tác mạng: %s\n", error_message);
  } CATCH(CALCULATION_ERROR) {
    printf("Lỗi tính toán dữ liệu: %s\n", error_message);
  }

  // In ra thông báo kết thúc chương trình
  printf("Kết thúc chương trình.\n");

  return 0;
}
