// 600fadb6  FUN_600fadb6  size=188 bytes
// --- callers ---
// --- callees ---
//   600f0b06 FUN_600f0b06
//   600a4060 FUN_600a4060
//   600c1a34 FUN_600c1a34


void FUN_600fadb6(int param_1,byte *param_2)

{
  int iVar1;
  undefined1 local_b;
  char local_a;
  byte local_9;
  
  local_9 = *param_2;
  *(undefined1 *)(param_1 + 0x2a) = 0;
  FUN_600f0b06(param_1 + 0x1d,local_9,&local_a);
  if (local_a == '\x02') {
    iVar1 = FUN_600a4060();
    *(bool *)(param_1 + 0x193) = iVar1 == 6;
    if ((*(char *)(param_1 + 0x193) == '\0') || ((local_9 & 8) != 0)) {
      *(byte *)(param_1 + 0x191) = local_9;
      *(undefined1 *)(param_1 + 0x1b4) = 0xf;
      *(undefined1 *)(param_1 + 0x1b5) = *(undefined1 *)(param_1 + 0x1b4);
      *(undefined1 *)(param_1 + 0x2a) = 2;
    }
    else {
      local_b = 3;
      FUN_600c1a34(param_1,0x17,&local_b);
    }
  }
  else if (local_a == '\x03') {
    *(undefined1 *)(param_1 + 0x1fb) = 1;
  }
  else if (local_a == '\x01') {
    FUN_600c1a34(param_1,0x18,0);
  }
  return;
}


