// 600acddc  FUN_600acddc  size=368 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   600ac524 FUN_600ac524
//   600f43c0 FUN_600f43c0
//   600b00b4 FUN_600b00b4
//   6006dbac FUN_6006dbac
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600acddc(int param_1,int param_2,undefined4 param_3,ushort param_4,undefined4 param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined2 local_1c;
  
  uVar1 = *(ushort *)(param_2 + 0x2c);
  if (*(char *)(param_2 + 0x31) == '\x02') {
    if (*(char *)(param_2 + 0x32) == '\x02') {
      if (*(int *)(param_2 + 0xc) == 0) {
        uVar2 = FUN_6006dbac(600,DAT_600acf4c,0x3a3);
        *(undefined4 *)(param_2 + 0xc) = uVar2;
      }
      if ((*(int *)(param_2 + 0xc) == 0) || (599 < uVar1)) {
        FUN_600b00b4(param_2,0x80,*(undefined4 *)(param_2 + 0xc));
      }
      else {
        local_1c = param_4;
        if (600 < (uint)uVar1 + (uint)param_4) {
          local_1c = 600 - uVar1;
        }
        *(ushort *)(param_2 + 0x2c) = local_1c + *(short *)(param_2 + 0x2c);
        thunk_EXT_FUN_0000b572((uint)uVar1 + *(int *)(param_2 + 0xc),param_5,local_1c);
        if (((uint)local_1c == *(ushort *)(param_1 + 0x1a) - 1) &&
           ((uint)uVar1 + (uint)local_1c < 600)) {
          FUN_600f43c0(param_2,*(undefined2 *)(param_2 + 0x2c));
        }
        else {
          FUN_600b00b4(param_2,0,*(undefined4 *)(param_2 + 0xc));
        }
      }
    }
    else {
      *(ushort *)(param_2 + 0x2c) = param_4;
      FUN_600b00b4(param_2,0,param_5);
    }
  }
  else if (((*(char *)(param_2 + 0x31) == '\x01') && (*(char *)(param_2 + 0x32) == '\x03')) &&
          (*(char *)(param_2 + 0x58) != '\0')) {
    *(undefined2 *)(param_2 + 0x28) = *(undefined2 *)(param_2 + 0x38);
    *(undefined1 *)(param_2 + 0x58) = 0;
    if (param_4 == 0x10) {
      thunk_EXT_FUN_0000b572(param_2 + 0x40,param_5,0x10);
      *(undefined2 *)(param_2 + 0x3c) = 0x10;
      if (*(int *)(*(int *)(param_2 + 4) + 0x1c) != 0) {
        (**(code **)(*(int *)(param_2 + 4) + 0x1c))
                  (*(undefined2 *)(param_2 + 0x24),*(undefined1 *)(param_2 + 0x32),param_2 + 0x3c);
      }
      FUN_600ac524(param_2);
    }
    else {
      FUN_600b00b4(param_2,4,param_5);
    }
  }
  return;
}


