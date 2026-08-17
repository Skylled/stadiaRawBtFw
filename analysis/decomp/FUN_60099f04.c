// 60099f04  FUN_60099f04  size=68 bytes
// --- callers ---
// --- callees ---


void FUN_60099f04(int param_1)

{
  undefined1 local_1c [8];
  undefined2 local_14;
  code *local_10;
  int local_c;
  
  local_c = *(int *)(param_1 + 0x10);
  if (local_c == 4) {
    local_10 = *(code **)(DAT_60099f48 + 0x754);
    local_1c[0] = 10;
    local_14 = 0;
    *(undefined4 *)(DAT_60099f48 + 0x754) = 0;
    if (local_10 != (code *)0x0) {
      (*local_10)(local_1c);
    }
  }
  return;
}


