// 600e049a  FUN_600e049a  size=46 bytes
// --- callers ---
// --- callees ---
//   600e7474 FUN_600e7474
//   600ea886 FUN_600ea886
//   600ea7fa FUN_600ea7fa


undefined4 FUN_600e049a(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x1c) == 0) ||
     (pcVar3 = *(code **)(*(int *)(param_1 + 0x1c) + 0x14), pcVar3 == (code *)0x0)) {
    iVar2 = FUN_600ea886(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    FUN_600ea7fa();
    FUN_600e7474();
  }
  else {
    (*pcVar3)();
  }
  uVar1 = func_0x600e0458();
  return uVar1;
}


