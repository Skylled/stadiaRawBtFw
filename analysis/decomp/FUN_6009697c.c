// 6009697c  FUN_6009697c  size=96 bytes
// --- callers ---
//   6006ba0c FUN_6006ba0c
// --- callees ---
//   6009655c FUN_6009655c


void FUN_6009697c(void)

{
  if (((*(char *)(DAT_600969dc + 100) != '\0') &&
      (((*(char *)(DAT_600969dc + 0x89) == '\x01' || (*(char *)(DAT_600969dc + 0x89) == '\x02')) ||
       (*(char *)(DAT_600969dc + 0x89) == '\a')))) && (*(char *)(DAT_600969dc + 0x67) == '\0')) {
    if (*(char *)(DAT_600969dc + 0x66) == '\0') {
      *(undefined1 *)(DAT_600969dc + 0x67) = 1;
    }
    else {
      *(undefined1 *)(DAT_600969dc + 0x67) = 2;
      FUN_6009655c();
    }
  }
  return;
}


