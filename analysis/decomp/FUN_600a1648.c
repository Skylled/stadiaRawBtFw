// 600a1648  FUN_600a1648  size=76 bytes
// --- callers ---
//   600f2532 FUN_600f2532
// --- callees ---


void FUN_600a1648(undefined1 *param_1)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  code *local_c;
  
  local_c = *(code **)(DAT_600a1694 + 0x700);
  *(undefined4 *)(DAT_600a1694 + 0x700) = 0;
  if (local_c != (code *)0x0) {
    local_10 = 3;
    local_f = *param_1;
    local_e = param_1[1];
    (*local_c)(&local_10);
  }
  return;
}


