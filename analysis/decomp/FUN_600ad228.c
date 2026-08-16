// 600ad228  FUN_600ad228  size=590 bytes
// --- callers ---
//   600aeb14 FUN_600aeb14
// --- callees ---


undefined1
FUN_600ad228(undefined4 *param_1,char param_2,short param_3,short param_4,int param_5,short param_6,
            byte param_7,byte param_8)

{
  ushort local_16;
  ushort local_14;
  short local_12;
  undefined4 *local_10;
  undefined1 local_9;
  
  local_12 = 0;
  if (param_1 != (undefined4 *)0x0) {
    for (local_10 = (undefined4 *)*param_1; local_10 != (undefined4 *)0x0;
        local_10 = (undefined4 *)*local_10) {
      if (param_3 == *(short *)(local_10 + 3)) {
        local_14 = *(ushort *)((int)local_10 + 10);
        local_16 = local_14 >> 0xc;
        if (local_16 != 0) {
          local_16 = local_16 + 6;
        }
        if (((param_2 == 'R') || (param_2 == '\x12')) && ((local_14 & 0x180) != 0)) {
          if (((local_14 & 0x80) == 0) || ((local_14 & 0x20) == 0)) {
            if ((((local_14 & 0x100) != 0) && ((local_14 & 0x20) != 0)) ||
               (((local_14 & 0x180) != 0 && ((local_14 & 0x40) != 0)))) {
              local_14 = 0x40;
            }
          }
          else {
            local_14 = 0x20;
          }
        }
        if ((param_2 == -0x2e) && ((param_7 & 4) != 0)) {
          return 4;
        }
        if ((local_14 & 0x1f0) == 0) {
          return 3;
        }
        if (((local_14 & 0xa0) != 0) && ((param_7 & 0x10) == 0)) {
          return 5;
        }
        if (((local_14 & 0x140) != 0) && ((param_7 & 0x20) == 0)) {
          return 5;
        }
        if (((local_14 & 0x60) != 0) && ((param_7 & 4) == 0)) {
          return 0xf;
        }
        if (((local_14 & 0x60) != 0) && (((param_7 & 4) != 0 && (param_8 < local_16)))) {
          return 0xc;
        }
        if (((local_14 & 0x180) != 0) &&
           (((param_2 != -0x2e && ((param_7 & 4) == 0)) && ((local_14 & 0x1f0) == 0)))) {
          return 5;
        }
        if (*(char *)(local_10 + 2) == '\0') {
          switch(*(undefined2 *)((int)local_10 + 0xe)) {
          case 0x2900:
          case 0x2904:
          case 0x2905:
          case 0x2906:
            local_9 = 3;
            break;
          case 0x2902:
          case 0x2903:
            local_12 = 2;
          default:
            local_9 = 0;
          }
        }
        else if ((*(char *)(local_10 + 2) == '\x01') || (*(char *)(local_10 + 2) == '\x02')) {
          local_9 = 0;
        }
        else {
          local_9 = 4;
        }
        if ((param_5 == 0) && (param_6 != 0)) {
          return 4;
        }
        if ((*(short *)((int)local_10 + 0xe) != 0x2902) &&
           (*(short *)((int)local_10 + 0xe) != 0x2903)) {
          return local_9;
        }
        if ((param_2 == '\x16') && (param_4 != 0)) {
          return 0xb;
        }
        if (param_6 != local_12) {
          return 0xd;
        }
        return 0;
      }
    }
  }
  return 10;
}


