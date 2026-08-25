// 600fb2ae  FUN_600fb2ae  size=92 bytes
// --- callers ---
// --- callees ---
//   600c2304 FUN_600c2304
//   600c1a34 FUN_600c1a34


void FUN_600fb2ae(int param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 local_d;
  undefined1 *local_c;
  
  local_d = 10;
  *(undefined1 *)(param_1 + 0x25) = *param_2;
  local_c = param_2;
  iVar1 = FUN_600c2304(param_1);
  if (iVar1 == 0) {
    if (local_c != (undefined1 *)0x0) {
      *(undefined1 *)(param_1 + 0x198) = *local_c;
    }
    *(undefined1 *)(param_1 + 0x2a) = 8;
  }
  else {
    FUN_600c1a34(param_1,0x17,&local_d);
  }
  return;
}


