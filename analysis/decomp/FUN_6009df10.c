// 6009df10  FUN_6009df10  size=194 bytes
// --- callers ---
//   6009d9d4 FUN_6009d9d4
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600b0b00 FUN_600b0b00


void FUN_6009df10(undefined1 param_1)

{
  ushort *puVar1;
  int iVar2;
  ushort *local_c;
  
  puVar1 = DAT_6009dfd4;
  if (*(int *)(DAT_6009dfd4 + 2) == 0) {
    if (*(int *)(DAT_6009dfd4 + 0x14) == 0) {
      local_c = DAT_6009dfd4 + 4;
    }
    else {
      local_c = *(ushort **)(DAT_6009dfd4 + 0x14);
    }
    if (0x1f - ((int)local_c - (int)(DAT_6009dfd4 + 4)) < 3) {
      *(ushort **)(DAT_6009dfd4 + 0x14) = DAT_6009dfd4 + 4;
      local_c = *(ushort **)(puVar1 + 0x14);
      thunk_EXT_FUN_0000b5ba(puVar1 + 4,0,0x1f);
    }
    *(undefined1 *)local_c = 2;
    *(undefined1 *)((int)local_c + 1) = 1;
    *(ushort **)(puVar1 + 2) = local_c + 1;
    *(undefined1 *)(local_c + 1) = param_1;
    *(undefined1 **)(puVar1 + 0x14) = (undefined1 *)((int)local_c + 3);
  }
  else {
    **(undefined1 **)(DAT_6009dfd4 + 2) = param_1;
  }
  iVar2 = FUN_600b0b00(*(int *)(puVar1 + 0x14) - (int)(puVar1 + 4) & 0xff,puVar1 + 4);
  if (iVar2 != 0) {
    *puVar1 = *puVar1 | 2;
  }
  return;
}


