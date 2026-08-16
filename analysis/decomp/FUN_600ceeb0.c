// 600ceeb0  FUN_600ceeb0  size=296 bytes
// --- callers ---
// --- callees ---
//   600cee6e FUN_600cee6e


void FUN_600ceeb0(int param_1,char *param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  ushort *puVar5;
  byte *pbVar6;
  int iVar7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    iVar7 = *(int *)(param_1 + 0x14);
    iVar2 = FUN_600cee6e(param_1,iVar7,param_3,*param_2,param_1);
    if (iVar2 == 0) {
      uVar3 = (*(uint *)(param_1 + 0x5c) & 0x7ffff) >> 0x10;
      iVar8 = 4 - (*(uint *)(param_1 + 0x5c) & 7);
LAB_600ceef0:
      iVar9 = iVar8;
switchD_600ceef8_switchD:
      switch(*param_2) {
      case '\x01':
        iVar8 = iVar9 + -1;
        if (iVar9 == 0) {
          return;
        }
        puVar5 = *(ushort **)(param_2 + 4);
        *(uint *)(param_1 + 0x60) = (uint)*puVar5;
        *(ushort **)(param_2 + 4) = puVar5 + 1;
        sVar1 = *(short *)(param_2 + 2);
        *(short *)(param_2 + 2) = sVar1 + -1;
        if ((short)(sVar1 + -1) != 0) goto LAB_600ceef0;
        if (*(int *)(param_2 + 0x2c) == 0) goto LAB_600cef78;
        *param_2 = '\x03';
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 0x28);
        *(short *)(param_2 + 2) = (short)*(int *)(param_2 + 0x2c);
        break;
      case '\x02':
        if (iVar9 == 0) {
          return;
        }
        *(uint *)(param_1 + 0x60) = *(int *)(param_2 + 0x2c) - 1U & 0xff | 0x100;
        *param_2 = '\x03';
        break;
      case '\x03':
        if (param_2[0x1e] == '\0') {
          if (iVar9 == 0) {
            return;
          }
          pbVar6 = *(byte **)(param_2 + 4);
          *(byte **)(param_2 + 4) = pbVar6 + 1;
          *(uint *)(param_1 + 0x60) = (uint)*pbVar6;
          uVar10 = uVar3;
          iVar9 = iVar9 + -1;
        }
        else {
          uVar10 = uVar3 - 1;
          if (uVar3 == 0) {
            return;
          }
          puVar4 = *(undefined1 **)(param_2 + 4);
          uVar11 = *(undefined4 *)(param_1 + 0x70);
          *(undefined1 **)(param_2 + 4) = puVar4 + 1;
          *puVar4 = (char)uVar11;
        }
        sVar1 = *(short *)(param_2 + 2);
        *(short *)(param_2 + 2) = sVar1 + -1;
        uVar3 = uVar10;
        iVar8 = iVar9;
        if ((short)(sVar1 + -1) == 0) {
LAB_600cef78:
          *param_2 = '\x04';
        }
        goto LAB_600ceef0;
      case '\x04':
        if (-1 < *(int *)(param_2 + 0x18) << 0x1d) goto code_r0x600cefa0;
        goto LAB_600cefb8;
      case '\x05':
        if (-1 < iVar7 << 0x16) {
          return;
        }
        goto LAB_600cefb8;
      default:
        goto switchD_600ceef8_switchD;
      }
      iVar8 = iVar9 + -1;
      if (param_2[0x1e] == '\x01') {
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffe;
      }
      goto LAB_600ceef0;
    }
LAB_600cefb8:
    UNRECOVERED_JUMPTABLE = *(code **)(param_2 + 0x30);
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xffffc1fc;
    *param_2 = '\0';
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x600cefdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(param_1,param_2,iVar2,*(undefined4 *)(param_2 + 0x34));
      return;
    }
  }
  return;
code_r0x600cefa0:
  if (iVar9 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x60) = 0x200;
  *param_2 = '\x05';
  iVar8 = iVar9 + -1;
  goto LAB_600ceef0;
}


