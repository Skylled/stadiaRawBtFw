// 600f414a  FUN_600f414a  size=82 bytes
// --- callers ---
// --- callees ---
//   600abbf4 FUN_600abbf4
//   600abdac FUN_600abdac


void FUN_600f414a(undefined2 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  
  iVar1 = FUN_600abbf4(param_1);
  if (((iVar1 != 0) && (param_3 == '\0')) && (*(char *)(iVar1 + 0x11) != '\0')) {
    *(undefined1 *)(iVar1 + 0x11) = 0;
    *(char *)(iVar1 + 0x10) = *(char *)(iVar1 + 0x10) + '\x01';
    FUN_600abdac(iVar1);
  }
  return;
}


