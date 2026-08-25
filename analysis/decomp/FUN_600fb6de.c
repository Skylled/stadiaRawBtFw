// 600fb6de  FUN_600fb6de  size=362 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600fb6de(int param_1,char *param_2)

{
  undefined1 local_a;
  char local_9;
  
  local_9 = *param_2;
  if (local_9 == '\0') {
    local_a = 0x14;
  }
  else {
    local_a = 0;
  }
  *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b4) & 0xf;
  *(byte *)(param_1 + 0x1b5) = *(byte *)(param_1 + 0x1b5) & 0xf;
  if (local_9 == '\x01') {
    if (*(char *)(param_1 + 0x195) == '\0') {
      *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b4) & 0xf7;
      *(byte *)(param_1 + 0x1b5) = *(byte *)(param_1 + 0x1b5) & 0xf7;
    }
    else {
      *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b4) | 1;
      *(byte *)(param_1 + 0x1b5) = *(byte *)(param_1 + 0x1b5) | 1;
      if (((*(byte *)(param_1 + 0x1b4) & 8) == 0) || ((*(byte *)(param_1 + 0x1b5) & 8) == 0)) {
        *(byte *)(param_1 + 0x1b4) = *(byte *)(param_1 + 0x1b4) & 0xf7;
        *(byte *)(param_1 + 0x1b5) = *(byte *)(param_1 + 0x1b5) & 0xf7;
      }
      if (*(char *)(param_1 + 0x26) == '\0') {
        *(byte *)(param_1 + 0x1b5) = *(byte *)(param_1 + 0x1b5) & 6;
      }
    }
    if ((*(char *)(param_1 + 0x1b4) == '\0') && (*(char *)(param_1 + 0x1b5) == '\0')) {
      FUN_600c1a34(param_1,0x17,&local_a);
    }
    else {
      FUN_600c1a34(param_1,0x19,0);
    }
  }
  else if (local_9 == '\0') {
    if ((*(ushort *)(param_1 + 0x28) & 0x10) == 0) {
      if (*(char *)(param_1 + 0x26) == '\0') {
        FUN_600c1a34(param_1,0x17,&local_a);
      }
    }
    else {
      FUN_600c1a34(param_1,0x17,&local_a);
    }
  }
  return;
}


