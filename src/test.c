#include "test.h"
#include <stdio.h>
int main(void) {
  int no_failed = 0;
  printf("..........／＞　  フ.....................\n");
printf("　　　　　| 　_　 _|\n");
printf("　 　　　／`ミ _x 彡\n");
printf("　　 　 /　　　 　 |\n");
printf("　　　 /　 ヽ　　 ﾉ\n");
printf("　／￣|　　 |　|　|\n");
printf("　| (￣ヽ＿_ヽ_)_)\n");
printf("　＼二つ\n");
  Suite *s;
  SRunner *runner;
  Suite *list_cases[] = {suite_strcspn(),  suite_memchr(),
                         suite_strchr(),   suite_strrchr(),
                         suite_strpbrk(),  suite_strstr(),
                         suite_strlen(),   suite_strerror(),
                         suite_strncat(),  suite_strtok(),
                            suite_sprintf(),
                         suite_memcpy(),   suite_memset(),
                         suite_strncpy(),  suite_strncmp(),
                         suite_memcmp(),   suite_insert(),
                         suite_trim(),     suite_to_upper(),
                         suite_to_lower(), NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    s = list_cases[i];
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
