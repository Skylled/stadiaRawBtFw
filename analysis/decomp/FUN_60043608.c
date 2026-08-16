// 60043608  FUN_60043608  size=144 bytes
// --- callers ---
// --- callees ---
//   600498b2 FUN_600498b2
//   6004bd8e FUN_6004bd8e


undefined4 FUN_60043608(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_3d8 [964];
  
  func_0x6004bcde(param_1 + 0x4fb8);
  if (*(uint *)(param_1 + 0x500c) < *(uint *)(param_1 + 0x5010)) {
    func_0x6004c1f4(auStack_3d8,PTR_s_CHECK_failed_60122ce9_9_6004369c,
                    PTR_s_append_buffer_h_60043698,0x3c);
    func_0x6004be44(auStack_3d8);
  }
  if (*(uint *)(param_1 + 0x5010) < 0x1e0) {
    uVar1 = 0;
  }
  else {
    FUN_6004bd8e(auStack_3d8,*(undefined4 *)(param_1 + 0x5014),0x3c0);
    func_0x6004c2c4(param_1 + 0x500c,*(undefined4 *)PTR_DAT_600436a0);
    if (*(int *)(param_1 + 0x70) != 0) {
      FUN_600498b2(*(int *)(param_1 + 0x70) + 0x1d8,auStack_3d8);
    }
    (**(code **)(**(int **)(param_1 + 0x3150) + 8))(*(int **)(param_1 + 0x3150),auStack_3d8,0x1e0);
    uVar1 = 1;
  }
  func_0x6004852c(param_1 + 0x4fb8);
  return uVar1;
}


