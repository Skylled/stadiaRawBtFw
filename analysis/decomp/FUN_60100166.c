// 60100166  FUN_60100166  size=224 bytes
// --- callers ---
//   600c8798 FUN_600c8798
// --- callees ---
//   601003da FUN_601003da
//   60100544 FUN_60100544


void FUN_60100166(int param_1,uint *param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int local_14;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  while (iVar1 = FUN_601003da(param_3,param_4), iVar1 != 0) {
    if ((*param_3 & 1) == 0) {
      local_c = 0;
    }
    else {
      local_c = *param_3 & 3;
      if (local_c == 1) {
        *param_3 = *param_3 & 0xfffffffe;
      }
      else {
        *param_3 = *param_3 + 1;
        if (*param_3 == 0) {
          local_14 = 1;
          do {
            param_3[local_14] = param_3[local_14] + 1;
            puVar2 = param_3 + local_14;
            local_14 = local_14 + 1;
          } while (*puVar2 == 0);
        }
      }
    }
    FUN_60100544(param_3,param_3,param_4);
    uVar3 = local_10;
    if ((int)local_10 < 0) {
      uVar3 = local_10 + 3;
    }
    uVar4 = local_10 & 3;
    if (-1 < (int)-local_10) {
      uVar4 = -(-local_10 & 3);
    }
    *(byte *)(param_1 + ((int)uVar3 >> 2)) =
         (byte)(local_c << ((uVar4 & 0x7f) << 1)) | *(byte *)(param_1 + ((int)uVar3 >> 2));
    local_10 = local_10 + 1;
  }
  *param_2 = local_10;
  return;
}


