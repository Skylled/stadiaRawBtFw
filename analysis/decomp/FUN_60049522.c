// 60049522  FUN_60049522  size=492 bytes
// --- callers ---
//   600432e8 FUN_600432e8
// --- callees ---


void FUN_60049522(int param_1,uint param_2,uint param_3,int param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 uVar5;
  code *pcVar6;
  bool bVar7;
  uint uVar8;
  uint uStack_20;
  int iStack_1c;
  
  if (*(char *)(param_3 + 3) != *(char *)(param_4 + 3)) {
    *(uint *)(param_1 + 0x40c) = param_2;
  }
  uVar8 = param_2;
  uStack_20 = param_3;
  iStack_1c = param_4;
  if (*(char *)(param_1 + 0x411) == '\0') {
    iVar4 = param_1;
    if ((*(int *)(param_1 + 0x3fc) != 0) && (*(char *)(param_1 + 0x410) == '\0')) {
      iVar4 = param_1 + 0x400;
      iVar2 = func_0x600494be(param_1,param_2,*(int *)(param_1 + 0x3fc),
                              *(undefined1 *)(param_4 + 0x12),iVar4,param_2);
      if (iVar2 != 0) {
        *(undefined1 *)(param_1 + 0x410) = 1;
        iVar2 = 0;
        if (*(char *)(param_4 + 3) != '\0') {
          if (param_2 - *(int *)(param_1 + 0x40c) < 0x116) {
            iVar2 = 0;
          }
          else {
            iVar2 = 1;
          }
        }
        puVar3 = *(undefined4 **)(param_1 + 0x244);
        if (puVar3 != (undefined4 *)0x0) {
          bVar7 = iVar2 == 0;
          if (bVar7) {
            iVar2 = 0;
          }
          if (!bVar7) {
            iVar2 = 2;
          }
          uStack_20 = 3;
          iStack_1c = iVar2;
          (**(code **)*puVar3)(puVar3,3,iVar2);
        }
      }
    }
  }
  else {
    iVar4 = param_1 + 0x408;
    iVar2 = func_0x600494be(param_1,param_2,*(undefined4 *)(param_1 + 0x404),
                            *(undefined1 *)(param_4 + 0x12),iVar4,param_2);
    if (iVar2 == 0) {
      if (param_2 <= *(uint *)(param_1 + 0x408)) goto LAB_6004957c;
    }
    else {
      puVar3 = *(undefined4 **)(param_1 + 0x244);
      if (puVar3 != (undefined4 *)0x0) {
        uStack_20 = 3;
        iStack_1c = 1;
        (**(code **)*puVar3)(puVar3,3,1);
      }
    }
    *(undefined1 *)(param_1 + 0x411) = 0;
  }
LAB_6004957c:
  if (*(char *)(param_3 + 0x12) != *(char *)(param_4 + 0x12)) {
    if (*(char *)(param_4 + 0x12) == '\0') {
      if ((*(char *)(param_1 + 0x410) == '\0') &&
         (puVar3 = *(undefined4 **)(param_1 + 0x244), puVar3 != (undefined4 *)0x0)) {
        uStack_20 = 3;
        iStack_1c = 3;
        (**(code **)*puVar3)(puVar3,3,3,&stack0xffffffe8,iVar4);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x410) = 0;
    }
  }
  uVar5 = 0;
  if (*(char *)(param_4 + 0x11) != '\0') {
    uVar5 = *(undefined1 *)(param_4 + 0xf);
  }
  iVar4 = func_0x600494be(param_1,param_2,3000,uVar5,param_1 + 0x3e4,uVar8);
  if (iVar4 != 0) {
    uStack_20 = uStack_20 & 0xffffff00;
    iVar4 = func_0x6004beac();
    if ((iVar4 != 0) ||
       ((cVar1 = func_0x6004c40c(0x19,&uStack_20), cVar1 == '\0' && ((char)uStack_20 != '\0')))) {
      uStack_20 = 3;
      iStack_1c = 5;
      (**(code **)**(undefined4 **)(param_1 + 0x244))(*(undefined4 **)(param_1 + 0x244),3,5);
    }
  }
  uVar5 = 0;
  if (*(char *)(param_4 + 3) != '\0') {
    uVar5 = *(undefined1 *)(param_4 + 0x12);
  }
  iVar4 = func_0x600494be(param_1,param_2,2000,uVar5,param_1 + 0x3ec,uVar8);
  if ((iVar4 != 0) && (puVar3 = *(undefined4 **)(param_1 + 0x244), puVar3 != (undefined4 *)0x0)) {
    uStack_20 = 0;
    iStack_1c = 0xf;
    (**(code **)*puVar3)(puVar3,0,0xf);
  }
  uVar5 = 0;
  if (*(char *)(param_4 + 0x11) != '\0') {
    uVar5 = *(undefined1 *)(param_4 + 0x10);
  }
  iVar4 = func_0x600494be(param_1,param_2,6000,uVar5,param_1 + 1000);
  if (iVar4 == 0) {
    if (*(char *)(param_3 + 0x10) == *(char *)(param_4 + 0x10)) {
      return;
    }
    if (*(char *)(param_4 + 0x10) != '\0') {
      return;
    }
    puVar3 = *(undefined4 **)(param_1 + 0x244);
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    pcVar6 = *(code **)*puVar3;
    uStack_20 = 3;
    iStack_1c = 4;
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x244);
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    pcVar6 = *(code **)*puVar3;
    uStack_20 = 1;
    iStack_1c = 9;
  }
  (*pcVar6)(puVar3,uStack_20,iStack_1c);
  return;
}


