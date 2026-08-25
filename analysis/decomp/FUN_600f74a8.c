// 600f74a8  FUN_600f74a8  size=130 bytes
// --- callers ---
//   600f3ed6 FUN_600f3ed6
//   600f7278 FUN_600f7278
//   600f3c42 FUN_600f3c42
// --- callees ---
//   600f5a98 FUN_600f5a98
//   600af814 FUN_600af814
//   600f717c FUN_600f717c
//   600afd28 FUN_600afd28
//   600f735a FUN_600f735a


char FUN_600f74a8(undefined1 param_1,char param_2,undefined4 param_3,undefined1 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_600af814(param_3,2);
  iVar3 = FUN_600afd28(param_1);
  if (iVar3 == 0) {
    cVar1 = '\0';
  }
  else if (param_2 == '\0') {
    cVar1 = FUN_600f735a(iVar3,param_3,param_4);
  }
  else {
    cVar1 = FUN_600f717c(iVar3,param_3,param_4);
    if ((cVar1 != '\0') && (iVar2 != 0)) {
      FUN_600f5a98(param_1,iVar2,1,1);
    }
  }
  return cVar1;
}


