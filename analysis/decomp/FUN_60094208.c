// 60094208  FUN_60094208  size=196 bytes
// --- callers ---
//   60093d20 FUN_60093d20
// --- callees ---
//   600a3424 FUN_600a3424
//   600a35e4 FUN_600a35e4
//   6013d3a0 thunk_EXT_FUN_0000b572


undefined4 FUN_60094208(int param_1,byte param_2)

{
  char cVar1;
  undefined1 auStack_14 [8];
  byte local_c;
  char local_a [2];
  
  local_a[0] = '\0';
  FUN_600a35e4(param_1,local_a);
  if (local_a[0] != '\x02') {
    thunk_EXT_FUN_0000b572(auStack_14,*DAT_600942cc + (uint)param_2 * 10,10);
    if ((*(byte *)(param_1 + 0xb) & 2) != 0) {
      local_c = local_c | 0x10;
    }
    cVar1 = FUN_600a3424(*(undefined1 *)(DAT_600942d0 + 0x124),param_1,auStack_14);
    if ((cVar1 == '\r') || (cVar1 == '\x01')) {
      *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xf9;
      *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) | 1;
    }
    else if (cVar1 == '\0') {
      *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xf8;
    }
    else {
      *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xf8;
    }
  }
  return 1;
}


