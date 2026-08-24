// 600ef510  FUN_600ef510  size=54 bytes
// --- callers ---
//   600ef546 FUN_600ef546
//   600ef57c FUN_600ef57c
// --- callees ---
//   600ef2da FUN_600ef2da


undefined4 FUN_600ef510(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(char *)(param_1 + 0x14) == *(char *)(param_2 + 0x14)) &&
     (iVar1 = FUN_600ef2da(param_1,param_2,1), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


