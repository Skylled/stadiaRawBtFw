// 6008f5e8  tasn_dec__6008f5e8  size=412 bytes
// src: tasn_dec.c
// --- callers ---
//   6008f794 tasn_dec__6008f794
// --- callees ---
//   6008f338 asn1_lib__6008f338
//   600e0552 FUN_600e0552
//   6008ee9c a_bitstr__6008ee9c
//   60090cb0 FUN_60090cb0
//   6008f2c0 asn1_lib__6008f2c0
//   6008f0d8 a_object__6008f0d8
//   60090ca4 FUN_60090ca4
//   6008ef7c a_int__6008ef7c
//   600ec720 FUN_600ec720
//   6013d208 thunk_EXT_FUN_0000ac5e
//   600ec5d2 FUN_600ec5d2


/* src: tasn_dec.c */

undefined4
tasn_dec__6008f5e8(uint *param_1,byte *param_2,uint param_3,uint param_4,char *param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  code *pcVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  byte *local_24;
  
  local_24 = param_2;
  if ((*(int *)(param_6 + 0x10) != 0) &&
     (pcVar5 = *(code **)(*(int *)(param_6 + 0x10) + 0x14), pcVar5 != (code *)0x0)) {
    uVar1 = (*pcVar5)();
    return uVar1;
  }
  if (*(int *)(param_6 + 4) == -4) {
    puVar3 = (uint *)*param_1;
    puVar6 = param_1;
    uVar9 = param_3;
    if (puVar3 == (uint *)0x0) {
      puVar3 = (uint *)FUN_60090ca4();
      if (puVar3 == (uint *)0x0) {
        puVar6 = (uint *)0x0;
        goto LAB_6008f660;
      }
      *param_1 = (uint)puVar3;
    }
    if (*puVar3 != param_4) {
      FUN_600ec5d2(puVar3,param_4,0,*puVar3,puVar6,param_2,uVar9);
    }
    puVar4 = puVar3 + 1;
    puVar6 = param_1;
  }
  else {
    puVar3 = (uint *)0x0;
    puVar6 = (uint *)0x0;
    puVar4 = param_1;
  }
  switch(param_4) {
  case 1:
    if (param_3 == 1) {
      *puVar4 = (uint)*local_24;
      return 1;
    }
    uVar1 = 0x6a;
    uVar8 = 0x38b;
    break;
  case 2:
  case 10:
    iVar2 = a_int__6008ef7c(puVar4,&local_24,param_3);
    if (iVar2 == 0) goto LAB_6008f660;
    *(uint *)(*puVar4 + 4) = *(uint *)(*puVar4 + 4) & 0x100 | param_4;
LAB_6008f6dc:
    if (puVar3 == (uint *)0x0) {
      return 1;
    }
    if (param_4 != 5) {
      return 1;
    }
LAB_6008f692:
    puVar3[1] = 0;
    return 1;
  case 3:
    iVar2 = a_bitstr__6008ee9c(puVar4,&local_24,param_3);
    goto LAB_6008f65e;
  default:
    if (param_4 == 0x1e) {
      if ((param_3 & 1) == 0) {
LAB_6008f718:
        puVar7 = (uint *)*puVar4;
        if (puVar7 == (uint *)0x0) {
          puVar7 = (uint *)asn1_lib__6008f338(param_4);
          if (puVar7 == (uint *)0x0) {
            uVar1 = 0x41;
            uVar8 = 0x3c0;
            break;
          }
          *puVar4 = (uint)puVar7;
        }
        else {
          puVar7[1] = param_4;
        }
        if (*param_5 == '\0') {
          iVar2 = asn1_lib__6008f2c0(puVar7,local_24,param_3);
          if (iVar2 == 0) {
            FUN_600e0552(0xc,0,0x41,DAT_6008f790,0x3d1);
            FUN_600ec720(puVar7);
            *puVar4 = 0;
            goto LAB_6008f660;
          }
        }
        else {
          if (puVar7[2] != 0) {
            thunk_EXT_FUN_0000ac5e();
          }
          *puVar7 = param_3;
          puVar7[2] = (uint)local_24;
          *param_5 = '\0';
        }
        goto LAB_6008f6dc;
      }
      uVar1 = 0x68;
      uVar8 = 0x3b5;
    }
    else {
      if ((param_4 != 0x1c) || ((param_3 & 3) == 0)) goto LAB_6008f718;
      uVar1 = 0xb5;
      uVar8 = 0x3b9;
    }
    break;
  case 5:
    if (param_3 == 0) {
      *puVar4 = 1;
      if (puVar3 == (uint *)0x0) {
        return 1;
      }
      goto LAB_6008f692;
    }
    uVar1 = 0xa4;
    uVar8 = 899;
    break;
  case 6:
    iVar2 = a_object__6008f0d8(puVar4,&local_24,param_3);
LAB_6008f65e:
    if (iVar2 != 0) {
      return 1;
    }
    goto LAB_6008f660;
  }
  FUN_600e0552(0xc,0,uVar1,DAT_6008f790,uVar8);
LAB_6008f660:
  FUN_60090cb0(puVar3);
  if (puVar6 != (uint *)0x0) {
    *puVar6 = 0;
    return 0;
  }
  return 0;
}


