// 600d6612  FUN_600d6612  size=34 bytes
// --- callers ---
//   60064110 usb_host_audio_topology__60064110
// --- callees ---
//   600d6588 FUN_600d6588


int FUN_600d6612(int param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_1 + 4);
  if (puVar1 == *(undefined2 **)(param_1 + 8)) {
    FUN_600d6588();
  }
  else {
    *puVar1 = *param_2;
    *(undefined2 **)(param_1 + 4) = puVar1 + 1;
  }
  return *(int *)(param_1 + 4) + -2;
}


