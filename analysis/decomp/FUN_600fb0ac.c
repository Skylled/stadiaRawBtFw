// 600fb0ac  FUN_600fb0ac  size=100 bytes
// --- callers ---
// --- callees ---
//   600c2304 FUN_600c2304
//   600c1a34 FUN_600c1a34


void FUN_600fb0ac(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 local_15;
  undefined1 *local_14;
  
  local_15 = 10;
  local_14 = param_2;
  iVar1 = FUN_600c2304(param_1);
  if (iVar1 == 0) {
    if (local_14 != (undefined1 *)0x0) {
      for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {
        *(undefined1 *)(param_1 + 0x3d + iVar1) = *local_14;
        local_14 = local_14 + 1;
      }
    }
    *(ushort *)(param_1 + 0x28) = *(ushort *)(param_1 + 0x28) | 8;
  }
  else {
    FUN_600c1a34(param_1,0x17,&local_15);
  }
  return;
}


