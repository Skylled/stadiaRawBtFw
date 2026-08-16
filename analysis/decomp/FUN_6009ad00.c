// 6009ad00  FUN_6009ad00  size=604 bytes
// --- callers ---
//   600fb346 FUN_600fb346
//   600fcdf4 FUN_600fcdf4
//   600fb4d0 FUN_600fb4d0
//   600f0568 FUN_600f0568
//   600fad26 FUN_600fad26
//   600fac38 FUN_600fac38
//   600fb43a FUN_600fb43a
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ff18 FUN_6009ff18


void FUN_6009ad00(undefined4 param_1,byte param_2,undefined4 *param_3,char param_4)

{
  byte local_14 [4];
  undefined4 *local_10;
  int local_c;
  
  local_c = FUN_6009ff18(param_1);
  if ((local_c != 0) && ((param_3 != (undefined4 *)0x0 || (param_2 == 0x20)))) {
    if (param_2 == 4) {
      thunk_EXT_FUN_0000b572(local_c + 0x9c,param_3 + 1,0x10);
      *(undefined1 *)(local_c + 0xda) = *(undefined1 *)(param_3 + 5);
      *(undefined4 *)(local_c + 0xdc) = *param_3;
      *(byte *)(local_c + 0x7b) = *(byte *)(local_c + 0x7b) | 4;
      *(ushort *)(local_c + 0x2a) = *(ushort *)(local_c + 0x2a) | 0x1000;
      if (*(char *)(param_3 + 5) == '\x04') {
        *(ushort *)(local_c + 0x2a) = *(ushort *)(local_c + 0x2a) | 0x2000;
      }
      else {
        *(ushort *)(local_c + 0x2a) = *(ushort *)(local_c + 0x2a) & 0xdfff;
      }
    }
    else if (param_2 < 5) {
      if (param_2 == 1) {
        thunk_EXT_FUN_0000b572(local_c + 0x8c,param_3,0x10);
        thunk_EXT_FUN_0000b572(local_c + 0xcc,param_3 + 4,8);
        *(undefined1 *)(local_c + 0xd8) = *(undefined1 *)((int)param_3 + 0x1a);
        *(undefined2 *)(local_c + 0xd4) = *(undefined2 *)(param_3 + 6);
        *(undefined1 *)(local_c + 0xd9) = *(undefined1 *)((int)param_3 + 0x1b);
        *(byte *)(local_c + 0x7b) = *(byte *)(local_c + 0x7b) | 1;
        *(ushort *)(local_c + 0x2a) = *(ushort *)(local_c + 0x2a) | 0x1000;
        if (*(char *)((int)param_3 + 0x1a) == '\x04') {
          *(ushort *)(local_c + 0x2a) = *(ushort *)(local_c + 0x2a) | 0x2000;
        }
        else {
          *(ushort *)(local_c + 0x2a) = *(ushort *)(local_c + 0x2a) & 0xdfff;
        }
      }
      else {
        if (param_2 != 2) {
          return;
        }
        thunk_EXT_FUN_0000b572(local_c + 0x7c,param_3,0x10);
        thunk_EXT_FUN_0000b572(local_c + 0x6c,(int)param_3 + 0x11,6);
        *(undefined1 *)(local_c + 0x6b) = *(undefined1 *)(param_3 + 4);
        *(byte *)(local_c + 0x7b) = *(byte *)(local_c + 0x7b) | 2;
      }
    }
    else if (param_2 == 0x20) {
      *(byte *)(local_c + 0x7b) = *(byte *)(local_c + 0x7b) | 0x20;
    }
    else if (param_2 == 0x40) {
      thunk_EXT_FUN_0000b572(local_c + 0xbc,(int)param_3 + 7,0x10);
      *(undefined2 *)(local_c + 0xd6) = *(undefined2 *)(param_3 + 1);
      *(undefined1 *)(local_c + 0xdb) = *(undefined1 *)((int)param_3 + 6);
      *(undefined4 *)(local_c + 0xe0) = *param_3;
      *(byte *)(local_c + 0x7b) = *(byte *)(local_c + 0x7b) | 0x40;
    }
    else {
      if (param_2 != 0x10) {
        return;
      }
      thunk_EXT_FUN_0000b572(local_c + 0xac,param_3,0x10);
      *(undefined2 *)(local_c + 0xd6) = *(undefined2 *)(param_3 + 4);
      *(undefined1 *)(local_c + 0xd8) = *(undefined1 *)((int)param_3 + 0x13);
      *(undefined1 *)(local_c + 0xd9) = *(undefined1 *)((int)param_3 + 0x12);
      *(byte *)(local_c + 0x7b) = *(byte *)(local_c + 0x7b) | 0x10;
    }
    if ((param_4 != '\0') && (*(int *)(DAT_6009af5c + 0x1138) != 0)) {
      local_14[0] = param_2;
      local_10 = param_3;
      (**(code **)(DAT_6009af5c + 0x1138))(0xd,param_1,local_14);
    }
  }
  return;
}


