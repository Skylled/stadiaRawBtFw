// 600c7aac  FUN_600c7aac  size=252 bytes
// --- callers ---
//   600ffada FUN_600ffada
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006dbac FUN_6006dbac
//   600f69f0 FUN_600f69f0


int FUN_600c7aac(ushort param_1,undefined4 *param_2)

{
  short sVar1;
  int local_1c;
  int local_18;
  short local_12;
  
  local_18 = 0;
  local_12 = *(short *)(param_2 + 6);
  local_18 = FUN_6006dbac(param_1 + 0x15,DAT_600c7ba8,0xa2);
  if (local_18 != 0) {
    *(undefined2 *)(local_18 + 4) = 0xd;
    *(undefined2 *)(local_18 + 2) = 5;
    *(undefined1 *)(local_18 + 0x15) = 6;
    *(char *)(local_18 + 0x16) = (char)*(undefined2 *)(param_2 + 5);
    *(char *)(local_18 + 0x17) = (char)((ushort)*(undefined2 *)(param_2 + 5) >> 8);
    *(char *)(local_18 + 0x18) = (char)*(undefined2 *)((int)param_2 + 0x16);
    local_1c = local_18 + 0x1a;
    *(char *)(local_18 + 0x19) = (char)((ushort)*(undefined2 *)((int)param_2 + 0x16) >> 8);
    sVar1 = FUN_600f69f0(&local_1c,*param_2,param_2[1],param_2[2],param_2[3],param_2[4]);
    *(short *)(local_18 + 2) = sVar1 + *(short *)(local_18 + 2);
    if ((uint)param_1 < (uint)*(ushort *)(param_2 + 6) + (uint)*(ushort *)(local_18 + 2)) {
      local_12 = param_1 - *(short *)(local_18 + 2);
    }
    thunk_EXT_FUN_0000b572(local_1c,(int)param_2 + 0x1a,local_12);
    *(short *)(local_18 + 2) = local_12 + *(short *)(local_18 + 2);
  }
  return local_18;
}


