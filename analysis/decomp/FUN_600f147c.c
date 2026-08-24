// 600f147c  FUN_600f147c  size=124 bytes
// --- callers ---
//   6009e338 FUN_6009e338
//   6009e098 FUN_6009e098
//   6009e1b4 FUN_6009e1b4
// --- callees ---


byte * FUN_600f147c(byte *param_1,byte param_2,char *param_3)

{
  byte *pbVar1;
  byte local_d;
  byte *local_c;
  
  local_d = *param_1;
  pbVar1 = param_1;
  while ((local_c = pbVar1 + 1, local_d != 0 && ((int)local_c - (int)param_1 < 0x3f))) {
    if (*local_c == param_2) {
      *param_3 = local_d - 1;
      return pbVar1 + 2;
    }
    pbVar1 = pbVar1 + 2 + (local_d - 1);
    local_d = *pbVar1;
  }
  *param_3 = '\0';
  return (byte *)0x0;
}


