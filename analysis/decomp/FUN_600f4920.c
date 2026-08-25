// 600f4920  FUN_600f4920  size=284 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   600af9fc FUN_600af9fc
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ac524 FUN_600ac524


void FUN_600f4920(undefined4 param_1,int param_2,undefined4 param_3,short param_4,char *param_5)

{
  int iVar1;
  short sVar2;
  ushort local_3c;
  byte *local_2c;
  undefined1 auStack_28 [20];
  short local_14;
  char local_a;
  byte local_9;
  
  local_9 = 0;
  if ((*(char *)(param_2 + 0x31) == '\x01') && (*(char *)(param_2 + 0x32) == '\x05')) {
    local_a = *param_5;
    local_2c = (byte *)(param_5 + 1);
    local_3c = param_4 - 1;
    if (local_a == '\x01') {
      local_9 = 2;
    }
    else if (local_a == '\x02') {
      local_9 = 0x10;
    }
    while ((ushort)(local_9 + 2) <= local_3c) {
      local_14 = (ushort)local_2c[1] * 0x100 + (ushort)*local_2c;
      local_2c = local_2c + 2;
      if (local_9 == 0) {
        thunk_EXT_FUN_0000b572(auStack_28,param_2 + 0x10,0x14);
      }
      else {
        iVar1 = FUN_600af9fc(auStack_28,local_9,&local_2c);
        if (iVar1 == 0) break;
      }
      local_3c = (local_3c - local_9) - 2;
      if (*(int *)(*(int *)(param_2 + 4) + 0x1c) != 0) {
        (**(code **)(*(int *)(param_2 + 4) + 0x1c))
                  (*(undefined2 *)(param_2 + 0x24),*(undefined1 *)(param_2 + 0x32),auStack_28);
      }
    }
    if (local_14 == 0) {
      sVar2 = 0;
    }
    else {
      sVar2 = local_14 + 1;
    }
    *(short *)(param_2 + 0x28) = sVar2;
    FUN_600ac524(param_2);
  }
  return;
}


