// 600dfa60  FUN_600dfa60  size=62 bytes
// --- callers ---
// --- callees ---
//   60082410 FUN_60082410


void FUN_600dfa60(uint param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint local_20;
  uint *puStack_1c;
  undefined4 uStack_18;
  
  local_20 = param_1;
  puStack_1c = param_2;
  uStack_18 = param_3;
  iVar1 = FUN_60082410(param_1,&local_20);
  if (iVar1 != 0) {
    uVar2 = (uint)(((uint)puStack_1c & 1) != 0) << 0x1f | local_20 >> 1;
    if ((local_20 & 1) == 0) {
      *param_2 = uVar2;
      param_2[1] = (uint)puStack_1c >> 1;
    }
    else {
      *param_2 = ~uVar2;
      param_2[1] = ~((uint)puStack_1c >> 1);
    }
  }
  return;
}


