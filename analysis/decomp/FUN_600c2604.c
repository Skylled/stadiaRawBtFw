// 600c2604  FUN_600c2604  size=138 bytes
// --- callers ---
// --- callees ---
//   600962dc FUN_600962dc
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60095ee8 FUN_60095ee8
//   6006dbac FUN_6006dbac


void FUN_600c2604(int param_1)

{
  undefined1 auStack_14 [6];
  undefined1 local_e;
  undefined2 *local_c;
  
  if (*DAT_600c2690 == '\x01') {
    thunk_EXT_FUN_0000b5ba(auStack_14,0,7);
    local_e = 1;
    if (*(int *)(param_1 + 8) != 0) {
      (**(code **)(param_1 + 8))(0,auStack_14);
    }
  }
  else {
    FUN_60095ee8(0,DAT_600c2694);
    if (*(int *)(param_1 + 8) != 0) {
      *(undefined4 *)(DAT_600c2690 + 0xe8) = *(undefined4 *)(param_1 + 8);
    }
    *DAT_600c2690 = '\x01';
    local_c = (undefined2 *)FUN_6006dbac(10,DAT_600c2698,0x13a);
    if (local_c != (undefined2 *)0x0) {
      *local_c = 0;
      local_c[4] = 0;
      FUN_600962dc(local_c);
    }
  }
  return;
}


