// 60094ba4  FUN_60094ba4  size=160 bytes
// --- callers ---
// --- callees ---
//   600ee9f6 FUN_600ee9f6
//   600eeb42 FUN_600eeb42
//   6009506c FUN_6009506c
//   600eead0 FUN_600eead0
//   60094d24 FUN_60094d24
//   600ef44c FUN_600ef44c
//   600eeaa6 FUN_600eeaa6


void FUN_60094ba4(undefined2 param_1,undefined1 param_2,char param_3)

{
  int iVar1;
  
  iVar1 = FUN_6009506c(param_1);
  if ((iVar1 == 0) || ((param_3 == '\0' && (*(char *)(iVar1 + 0x1d) == '\0')))) {
    iVar1 = FUN_600ef44c(param_1);
    if (iVar1 != 0) {
      switch(param_2) {
      case 1:
      case 2:
        FUN_600ee9f6(param_1,iVar1);
        break;
      case 3:
        FUN_600eeaa6(param_1,iVar1);
        break;
      case 4:
        FUN_600eead0(param_1,iVar1);
        break;
      case 5:
        FUN_600eeb42(param_1,iVar1);
      }
    }
  }
  else {
    if (*(char *)(iVar1 + 0x1d) == '\0') {
      *(char *)(iVar1 + 0x1d) = param_3;
    }
    FUN_60094d24(iVar1,0x1d0f,0);
  }
  return;
}


