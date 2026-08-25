// 600f622a  FUN_600f622a  size=276 bytes
// --- callers ---
//   600f38d0 FUN_600f38d0
//   600adeb4 FUN_600adeb4
// --- callees ---
//   600f6f52 FUN_600f6f52
//   600f6e4a FUN_600f6e4a
//   600adce0 FUN_600adce0
//   600f6fd2 FUN_600f6fd2
//   600f6ee2 FUN_600f6ee2
//   600ff9fe FUN_600ff9fe
//   600c7eb8 FUN_600c7eb8
//   600f6be6 FUN_600f6be6
//   600adc88 FUN_600adc88


undefined1
FUN_600f622a(int param_1,undefined1 param_2,undefined4 param_3,char param_4,char param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_9;
  
  local_9 = 0;
  FUN_600f6f52(param_1,param_2,0,0);
  if (param_4 == '\x0e') {
    iVar1 = FUN_600adce0(param_1 + 0x28,param_5,param_6,*(undefined2 *)(param_1 + 0x1a));
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    if ((param_4 == '\x16') && (param_5 == '\0')) {
      FUN_600f6fd2(param_1,param_2,1,0);
    }
    if ((param_4 == '\x18') && (param_5 != '\0')) {
      FUN_600f6ee2(param_1);
    }
    *(char *)(param_1 + 0x57) = param_5;
    iVar1 = FUN_600f6e4a(param_1);
    if (((iVar1 != 0) && (param_5 == '\0')) && (*(int *)(param_1 + 0x28) == 0)) {
      uVar2 = FUN_600c7eb8(param_1,param_4 + '\x01',param_6);
      *(undefined4 *)(param_1 + 0x28) = uVar2;
    }
  }
  iVar1 = FUN_600f6e4a(param_1);
  if (iVar1 != 0) {
    if ((*(char *)(param_1 + 0x57) == '\0') && (*(int *)(param_1 + 0x28) != 0)) {
      local_9 = FUN_600ff9fe(param_1,*(undefined4 *)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    else {
      local_9 = FUN_600f6be6(param_1,param_5,param_4,*(undefined2 *)(param_1 + 0x54),0);
    }
    FUN_600adc88(param_1);
  }
  return local_9;
}


