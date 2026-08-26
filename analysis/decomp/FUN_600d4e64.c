// 600d4e64  FUN_600d4e64  size=34 bytes
// --- callers ---
//   6005b8dc application_state__6005b8dc
//   60075088 audio_states__60075088
// --- callees ---
//   600d105e FUN_600d105e
//   600d1066 FUN_600d1066


void FUN_600d4e64(int param_1)

{
  if (*(int *)(param_1 + 0x90) == 2) {
    FUN_600d1066(*(undefined4 *)(param_1 + 0x98));
    FUN_600d105e(*(undefined4 *)(param_1 + 0x98));
    return;
  }
  return;
}


