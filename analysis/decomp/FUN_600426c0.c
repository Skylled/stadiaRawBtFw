// 600426c0  FUN_600426c0  size=306 bytes
// --- callers ---
// --- callees ---
//   60047b98 tasks__60047b98
//   60047f50 FUN_60047f50


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_600426c0(byte *param_1,undefined2 param_2,undefined4 param_3,uint param_4,
                 undefined4 param_5,ushort param_6,undefined4 param_7)

{
  code *pcVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined1 uStack_32;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  uVar6 = (uint)param_6;
  iVar3 = func_0x6004bce8(param_1 + 0xa4,param_7);
  puVar2 = PTR_DAT_600427f4;
  if (iVar3 == 0) {
    return 4;
  }
  if (param_1[0x158] != 0) {
    if (3 < *param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0x600427f0);
      (*pcVar1)();
    }
    if ((*(int *)(*(int *)(PTR_DAT_600427f4 + (uint)*param_1 * 4) + 0x14) << 6 < 0) &&
       (uVar5 = func_0x6004c164(), uVar5 < *(int *)(param_1 + 0x15c) + 1U)) {
      func_0x6004c304(0x14,PTR_s_i2c_cc_600427fc,100,
                      PTR_s_Delaying_I2C_until_startup_time_c_600427f8);
      tasks__60047b98(1);
    }
    iVar3 = FUN_60047f50();
    if (iVar3 == 2) {
      if (param_4 == 0) {
LAB_6004279e:
        if (uVar6 != 0) {
          uVar4 = 0;
          uStack_32 = 1;
          uStack_38 = 0;
          uStack_28 = param_5;
          uStack_30 = 0;
          uStack_2c = 0;
          if (*param_1 < 4) {
            uVar4 = *(undefined4 *)(puVar2 + (uint)*param_1 * 4);
          }
          uStack_34 = param_2;
          uStack_24 = uVar6;
          func_0x6004c244(uVar4,param_1 + 0x6c,&uStack_38);
          uVar5 = func_0x600491b2();
          if ((uVar5 & 0xff) != 0) goto LAB_600426f6;
          func_0x6004bedc(param_1 + 0xf8);
          if (*(int *)(param_1 + 0x154) != 0) goto LAB_60042798;
        }
        uVar5 = 0;
      }
      else {
        uVar4 = 0;
        uStack_32 = 0;
        if (uVar6 == 0) {
          uStack_38 = 0;
        }
        else {
          uStack_38 = 4;
        }
        uStack_30 = 0;
        uStack_2c = 0;
        if (*param_1 < 4) {
          uVar4 = *(undefined4 *)(puVar2 + (uint)*param_1 * 4);
        }
        uStack_34 = param_2;
        uStack_28 = param_3;
        uStack_24 = param_4;
        func_0x6004c244(uVar4,param_1 + 0x6c,&uStack_38);
        uVar5 = func_0x600491b2();
        if ((uVar5 & 0xff) != 0) goto LAB_600426f6;
        func_0x6004bedc(param_1 + 0xf8);
        if (*(int *)(param_1 + 0x154) == 0) goto LAB_6004279e;
LAB_60042798:
        uVar5 = func_0x600491b2();
      }
      goto LAB_600426f6;
    }
    func_0x6004c304(0x28,PTR_s_i2c_cc_600427fc,0x6a,PTR_s_I2c_operations_only_supported_af_60042800)
    ;
  }
  uVar5 = 9;
LAB_600426f6:
  func_0x6004852c(param_1 + 0xa4);
  return uVar5;
}


