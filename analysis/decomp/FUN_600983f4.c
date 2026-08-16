// 600983f4  FUN_600983f4  size=308 bytes
// --- callers ---
// --- callees ---
//   60098f34 FUN_60098f34


void FUN_600983f4(char param_1,char *param_2)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  undefined1 auStack_24 [5];
  byte local_1f [3];
  int local_1c;
  byte local_17;
  short local_16;
  byte local_14;
  byte local_13;
  char local_12;
  char local_11;
  
  local_11 = *param_2;
  if ((local_11 == -0x17) && (1 < (byte)(param_1 - 1U))) {
    local_12 = param_2[1];
    if ((local_12 == '\x03') && (8 < (byte)(param_1 - 2U))) {
      pbVar1 = local_1f;
      pbVar3 = (byte *)(param_2 + 2);
      for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
        *pbVar1 = *pbVar3;
        pbVar1 = pbVar1 + -1;
        pbVar3 = pbVar3 + 1;
      }
      local_13 = pbVar3[1];
      local_14 = pbVar3[2];
      if (*(int *)(DAT_60098528 + 0xc4) != 0) {
        (**(code **)(DAT_60098528 + 0xc4))
                  (auStack_24,local_13,(int)(char)local_14,*(code **)(DAT_60098528 + 0xc4),
                   pbVar3 + 3);
      }
    }
    else if ((local_12 == '\x02') && (3 < (byte)(param_1 - 2U))) {
      local_16 = (ushort)(byte)param_2[3] * 0x100 + (ushort)(byte)param_2[2];
      local_13 = param_2[4];
      local_14 = param_2[5];
      param_2 = param_2 + 6;
      local_17 = FUN_60098f34(local_16);
      if ((local_17 != 4) &&
         (local_1c = (uint)local_17 * 0x14c + 0x110 + DAT_6009852c, *(int *)(local_1c + 0x148) != 0)
         ) {
        (**(code **)(local_1c + 0x148))
                  (local_1c + 6,local_13,(int)(char)local_14,local_1c + 6,param_2);
      }
    }
  }
  return;
}


