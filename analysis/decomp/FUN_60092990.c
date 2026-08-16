// 60092990  FUN_60092990  size=96 bytes
// --- callers ---
// --- callees ---
//   600962dc FUN_600962dc
//   6006dbac FUN_6006dbac


void FUN_60092990(char param_1)

{
  undefined2 *puVar1;
  undefined2 local_a;
  
  if (param_1 == '\0') {
    local_a = 0x2a04;
  }
  else if (param_1 == '\x01') {
    local_a = 0x2a05;
  }
  else {
    if (param_1 != '\x02') {
      return;
    }
    local_a = 0x2a06;
  }
  puVar1 = (undefined2 *)FUN_6006dbac(8,DAT_600929f0,0x50);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = local_a;
    FUN_600962dc(puVar1);
  }
  return;
}


