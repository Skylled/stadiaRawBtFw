// 6004244c  FUN_6004244c  size=242 bytes
// --- callers ---
// --- callees ---
//   60041028 FUN_60041028


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_6004244c(char *param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  bool bVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcStack_20;
  undefined4 *puStack_1c;
  
  uVar5 = _DAT_60042548;
  cVar1 = *param_1;
  pcStack_20 = param_1;
  puStack_1c = param_2;
  if (*_DAT_60042540 == '\0') {
    bVar2 = false;
    if ((*(uint *)(_DAT_60042544 + 0x14) & 0xfff) >> 8 == 3) {
      *_DAT_60042540 = '\x01';
      func_0x6004c304(10,_DAT_6004254c,0x43,uVar5);
      bVar2 = true;
    }
  }
  else {
    bVar2 = false;
  }
  if (cVar1 == '\x01') {
    if (*param_1 == '\x01') {
      iVar6 = *(int *)(param_1 + 4);
    }
    else {
      iVar6 = -1;
    }
    if (((int)(_DAT_60042550[4] << 3) < 0) && (*param_3 == iVar6)) {
      *(undefined1 *)(param_2 + 1) = 4;
      goto LAB_6004250e;
    }
    if (iVar6 == 1) {
      FUN_60041028(_DAT_60042554,0);
      uVar4 = 0;
      uVar5 = _DAT_60042558;
    }
    else if (iVar6 == 0) {
      FUN_60041028(_DAT_60042554,0);
      uVar4 = 1;
      uVar5 = _DAT_60042558;
    }
    else {
      if (iVar6 != 2) {
        return 3;
      }
      uVar4 = 1;
      uVar5 = _DAT_60042554;
    }
    FUN_60041028(uVar5,uVar4);
    func_0x6004c304(10,_DAT_6004254c,0x73,_DAT_6004255c);
    *param_3 = iVar6;
    *(undefined1 *)(param_2 + 1) = 4;
  }
  else {
    if (cVar1 == '\0') {
      *(undefined1 *)(param_2 + 1) = 0;
    }
LAB_6004250e:
    if (!bVar2) goto LAB_60042512;
  }
  puVar3 = _DAT_60042550;
  *_DAT_60042550 = *_DAT_60042550 | 0x80000000;
  func_0x6004c3f4(puVar3);
  func_0x6004c0c4(&pcStack_20);
  func_0x6004c12c(puVar3,&pcStack_20);
LAB_60042512:
  *param_2 = 0x10000;
  if (*param_1 == '\0') {
    uVar5 = *(undefined4 *)(param_1 + 4);
  }
  else {
    uVar5 = 0;
  }
  func_0x60048b0c(_DAT_60042550,param_2,uVar5,*(undefined4 *)(param_1 + 8));
  uVar5 = func_0x600491b2();
  return uVar5;
}


