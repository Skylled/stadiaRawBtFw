// 600f7bd8  FUN_600f7bd8  size=106 bytes
// --- callers ---
//   600fb9b4 FUN_600fb9b4
//   600fe05a FUN_600fe05a
//   600c63e0 FUN_600c63e0
//   600fb93a FUN_600fb93a
// --- callees ---
//   600b5844 FUN_600b5844
//   600bb6dc FUN_600bb6dc


undefined4 FUN_600f7bd8(undefined4 param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600bb6dc(param_1,2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (*(char *)(iVar1 + 0x32) == '\x02') {
    if (param_2 == '\0') {
      *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) | 1;
    }
    else {
      *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) & 0xfe;
    }
    FUN_600b5844(iVar1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


