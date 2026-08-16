// 60047be8  FUN_60047be8  size=160 bytes
// --- callers ---
//   6004166c FUN_6004166c
// --- callees ---
//   6004c084 thunk_FUN_601016a2
//   60041c50 FUN_60041c50


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60047be8(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = _DAT_60047c90;
  if (*_DAT_60047c88 == 0) {
    *_DAT_60047c8c = 0;
    func_0x6004904a(*piVar1);
    uVar4 = FUN_60041c50();
    puVar2 = _DAT_60047c94;
    if (*_DAT_60047c94 < uVar4) {
      *(uint *)(*piVar1 + 0x60) = (*(int *)(*piVar1 + 0x60) - *_DAT_60047c94) + uVar4;
    }
    *puVar2 = uVar4;
    if (*(uint *)*piVar1 <= *(uint *)(*piVar1 + 0x30)) {
      func_0x6004bf44(*piVar1,*piVar1 + 0x34);
    }
    iVar3 = _DAT_60047c9c;
    iVar7 = 0x1f - LZCOUNT(*_DAT_60047c98);
    if (*(int *)(_DAT_60047c9c + iVar7 * 0x14) == 0) {
      thunk_FUN_601016a2(_DAT_60047ca4,0xc6d,_DAT_60047ca0);
    }
    iVar6 = iVar3 + iVar7 * 0x14;
    iVar5 = *(int *)(*(int *)(iVar6 + 4) + 4);
    *(int *)(iVar6 + 4) = iVar5;
    if (iVar5 == iVar7 * 0x14 + 8 + iVar3) {
      *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(iVar5 + 4);
    }
    *piVar1 = *(int *)(*(int *)(iVar7 * 0x14 + iVar3 + 4) + 0xc);
    func_0x60049044(*piVar1);
    *_DAT_60047ca8 = *piVar1 + 100;
  }
  else {
    *_DAT_60047c8c = 1;
  }
  return;
}


