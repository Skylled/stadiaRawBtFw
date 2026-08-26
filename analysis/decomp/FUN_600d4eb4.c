// 600d4eb4  FUN_600d4eb4  size=20 bytes
// --- callers ---
// --- callees ---


undefined4 FUN_600d4eb4(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
    (**(code **)(param_1 + 0xc))(param_2,param_3);
  }
  return 0;
}


