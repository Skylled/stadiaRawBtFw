// 600b8888  FUN_600b8888  size=300 bytes
// --- callers ---
//   600a5540 FUN_600a5540
// --- callees ---
//   600b233c FUN_600b233c
//   600bb44c FUN_600bb44c
//   6009fe40 FUN_6009fe40
//   600bb740 FUN_600bb740
//   600bb6dc FUN_600bb6dc
//   600b22a8 FUN_600b22a8
//   600aa340 FUN_600aa340


undefined4 FUN_600b8888(undefined4 param_1)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int local_10;
  char *local_c;
  
  iVar4 = FUN_600bb6dc(param_1,1);
  if (iVar4 == 0) {
    pcVar5 = (char *)FUN_600bb44c(param_1,0,1);
    if (pcVar5 == (char *)0x0) {
      FUN_600b233c(param_1,0xd);
      uVar7 = 0;
    }
    else {
      bVar1 = true;
      local_c = DAT_600b89b4;
      for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
        if ((local_c != pcVar5) && (*local_c != '\0')) {
          bVar1 = false;
          pcVar5[10] = '\0';
          break;
        }
        local_c = local_c + 0xa4;
      }
      if (bVar1) {
        iVar4 = FUN_6009fe40(param_1);
        if (iVar4 == 0) {
          pcVar5[10] = '\x01';
        }
        else {
          cVar2 = FUN_600bb740(pcVar5);
          pcVar5[10] = cVar2;
        }
      }
      FUN_600b22a8(param_1,pcVar5[10]);
      pcVar5[1] = '\x03';
      FUN_600aa340(pcVar5 + 0x44,2,0x3c);
      uVar7 = 1;
    }
  }
  else if ((*(char *)(iVar4 + 1) == '\x03') || (*(char *)(iVar4 + 1) == '\x01')) {
    iVar6 = FUN_6009fe40(param_1);
    if (iVar6 == 0) {
      *(undefined1 *)(iVar4 + 10) = 1;
    }
    else {
      uVar3 = FUN_600bb740(iVar4);
      *(undefined1 *)(iVar4 + 10) = uVar3;
    }
    FUN_600b22a8(param_1,*(undefined1 *)(iVar4 + 10));
    *(undefined1 *)(iVar4 + 1) = 3;
    uVar7 = 1;
  }
  else {
    if (*(char *)(iVar4 + 1) == '\x05') {
      FUN_600b233c(param_1,0xf);
    }
    else {
      FUN_600b233c(param_1,0xb);
    }
    uVar7 = 0;
  }
  return uVar7;
}


