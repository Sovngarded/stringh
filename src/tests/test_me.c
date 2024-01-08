#include "test_me.h"

int main(void) {
  int failed = 0;
printf("..........／＞　  フ.....................\n");
printf("　　　　　| 　_　 _|\n");
printf("　 　　　／`ミ _x 彡\n");
printf("　　 　 /　　　 　 |\n");
printf("　　　 /　 ヽ　　 ﾉ\n");
printf("　／￣|　　 |　|　|\n");
printf("　| (￣ヽ＿_ヽ_)_)\n");
printf("　＼二つ\n");
Suite *s21_string_test[] = {test_memchr(),
                              test_memcmp(),
                              test_memcpy(),
                              test_memset(),
                              test_strncat(),
                              test_strchr(),
                              // test_strcmp(),
                              test_strncmp(),
                              test_strcpy(),
                              test_strncpy(),
                              test_strcspn(),
                              test_strerror(),
                              test_strlen(),
                              test_strpbrk(),
                              test_strrchr(),
                              // test_strspn(),
                         test_strstr(),
                              test_strtok(),
                              test_sprintf_f(),
                               test_sprintf_e(),
                              test_sprintf_g(), //sega
                              //  test_sprintf_octal(), good 
                                //  test_sprintf_HEX(), // good
                              //  test_sprintf_hex(), // good
                               test_sprintf_pointer(),
                             //test_sprintf_percent(), //good
                              //test_sprintf_n(), // good 
                              // test_sprintf_unsigned() , // good
                              // test_sprintf_signed_i(), // good
                              test_sprintf_string(),
                              test_sprintf_signed(),
                              // test_sscanf_empty(),
                              // test_sscanf_c(),
                              // test_sscanf_d(),
                              // test_sscanf_i(),
                              // test_sscanf_o(),
                              // test_sscanf_x(),
                              // test_sscanf_p(),
                              // test_sscanf_real(),
                              // test_sscanf_n(),
                              test_to_upper(),
                              test_to_lower(),
                              test_insert(),
                              test_trim(),
                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 0 : 1;
}