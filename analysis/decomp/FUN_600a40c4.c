// 600a40c4  FUN_600a40c4  size=412 bytes
// --- callers ---
//   600f1996 FUN_600f1996
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


char FUN_600a40c4(char param_1,undefined4 param_2,char param_3,ushort param_4,short param_5,
                 int param_6,int param_7)

{
  ushort local_1c;
  char local_11;
  ushort local_10;
  ushort local_e;
  int *local_c;
  
  local_10 = 0xffff;
  local_11 = '\0';
  local_c = DAT_600a4260;
  local_e = 0;
  do {
    if (0xd < local_e) {
LAB_600a414e:
      if (local_11 != '\0') {
        if (0xd < local_e) {
          local_c = (int *)(DAT_600a4264 + (uint)local_10 * 0x14 + 0x11b0);
        }
        *(short *)(local_c + 3) = param_5;
        *(char *)(local_c + 4) = param_3;
        *local_c = param_6;
        if (param_1 == '\0') {
          local_c[2] = param_7;
          *(ushort *)((int)local_c + 0xe) = (ushort)DAT_600a426c & *(ushort *)((int)local_c + 0xe);
          local_1c = param_4 & 0xdfc7;
          if ((3 < *(byte *)(DAT_600a4264 + 0x1174)) && ((param_4 & 2) != 0)) {
            local_1c = local_1c | 0x1000;
          }
          if ((local_1c & 4) != 0) {
            local_1c = local_1c | 2;
          }
        }
        else {
          local_c[1] = param_7;
          *(ushort *)((int)local_c + 0xe) = (ushort)DAT_600a4268 & *(ushort *)((int)local_c + 0xe);
          local_1c = param_4 & 0xeff8;
          if ((3 < *(byte *)(DAT_600a4264 + 0x1174)) && ((param_4 & 0x10) != 0)) {
            local_1c = local_1c | 0x2000;
          }
          if ((local_1c & 0x20) != 0) {
            local_1c = local_1c | 0x10;
          }
          *(int **)(DAT_600a4264 + 0x1aa8) = local_c;
        }
        *(ushort *)((int)local_c + 0xe) = local_1c | *(ushort *)((int)local_c + 0xe) | 0x80;
      }
      return local_11;
    }
    if ((*(ushort *)((int)local_c + 0xe) & 0x80) == 0) {
      if (local_11 == '\0') {
        thunk_EXT_FUN_0000b5ba(local_c,0,0x14,0,param_2);
        local_11 = '\x01';
        local_10 = local_e;
      }
    }
    else if (((param_5 == (short)local_c[3]) && (param_6 == *local_c)) &&
            (param_3 == (char)local_c[4])) {
      local_11 = '\x01';
      goto LAB_600a414e;
    }
    local_e = local_e + 1;
    local_c = local_c + 5;
  } while( true );
}


