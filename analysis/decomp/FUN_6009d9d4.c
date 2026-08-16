// 6009d9d4  FUN_6009d9d4  size=206 bytes
// --- callers ---
// --- callees ---
//   6009df10 FUN_6009df10


void FUN_6009d9d4(ushort param_1,ushort param_2)

{
  byte bVar1;
  undefined1 local_9;
  
  local_9 = 0;
  if (*(int *)(DAT_6009daa4 + 4) != 0) {
    local_9 = **(byte **)(DAT_6009daa4 + 4);
  }
  bVar1 = local_9;
  if (((param_2 & 3) == 0) && ((param_1 & 1) == 0)) {
    local_9 = local_9 | 4;
  }
  else {
    local_9 = local_9 & 0xfb;
  }
  if ((*(byte *)(DAT_6009daa8 + 0x819) & 2) == 0) {
    local_9 = local_9 & 0xe7;
  }
  else {
    local_9 = local_9 | 0x18;
  }
  if ((param_2 & 0x100) == 0) {
    if ((param_2 & 0x200) == 0) {
      local_9 = local_9 & 0xfc;
    }
    else {
      local_9 = local_9 & 0xfe | 2;
    }
  }
  else {
    local_9 = local_9 & 0xfd | 1;
  }
  if (local_9 != bVar1) {
    FUN_6009df10(local_9);
  }
  return;
}


