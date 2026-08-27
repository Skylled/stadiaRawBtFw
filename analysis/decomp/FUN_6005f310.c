// 6005f310  FUN_6005f310  size=156 bytes
// --- callers ---
//   6005f450 dcp_encryption_engine__6005f450
// --- callees ---
//   60052c78 FUN_60052c78
//   60052ccc FUN_60052ccc
//   6013d178 thunk_EXT_FUN_00008996


char FUN_6005f310(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 uint param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar7;
  
  uVar2 = DAT_6005f3b4;
  puVar1 = DAT_6005f3ac;
  if ((param_5 < 0x10) || (puVar5 = param_3, puVar9 = param_3, (param_5 & 0xf) != 0)) {
    cVar3 = '\x03';
  }
  else {
    do {
      puVar8 = puVar5 + 4;
      puVar4 = DAT_6005f3ac;
      puVar6 = puVar5;
      do {
        puVar7 = puVar6 + 1;
        *puVar4 = *puVar6;
        puVar4 = puVar4 + 1;
        puVar6 = puVar7;
      } while (puVar7 != puVar8);
      if (*param_1 == 0) {
        FUN_60052c78(uVar2,param_2);
        cVar3 = thunk_EXT_FUN_00008996();
        param_6 = param_4;
      }
      else {
        FUN_60052ccc(uVar2,param_2,puVar1,DAT_6005f3b0,0x10,param_6,puVar9);
        cVar3 = thunk_EXT_FUN_00008996();
        param_6 = puVar5;
      }
      if (cVar3 != '\0') {
        return cVar3;
      }
      puVar6 = DAT_6005f3b0 + 4;
      puVar5 = param_4;
      puVar4 = DAT_6005f3b0;
      do {
        puVar7 = puVar4 + 1;
        *puVar5 = *puVar4;
        puVar5 = puVar5 + 1;
        puVar4 = puVar7;
      } while (puVar7 != puVar6);
      param_4 = param_4 + 4;
      puVar5 = puVar8;
    } while (puVar8 != (undefined4 *)((int)param_3 + param_5));
    cVar3 = '\0';
  }
  return cVar3;
}


