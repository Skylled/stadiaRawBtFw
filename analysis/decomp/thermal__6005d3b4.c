// 6005d3b4  thermal__6005d3b4  size=534 bytes
// src: thermal.cc
// --- callers ---
//   6005d634 thermal__6005d634
// --- callees ---
//   600d6e14 FUN_600d6e14
//   60066070 keys__60066070
//   600683f4 battery_charger_bq25601__600683f4
//   600cc984 FUN_600cc984
//   6013cef8 thunk_EXT_FUN_0000737c
//   600cc8f8 FUN_600cc8f8
//   6005d12c FUN_6005d12c
//   6006859c FUN_6006859c
//   6005d160 thermal__6005d160
//   6005d714 trigger_bug_report__6005d714
//   600d4330 FUN_600d4330
//   6010165c FUN_6010165c
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600cae18 timers__600cae18
//   60068604 FUN_60068604
//   600d6dda FUN_600d6dda
//   60068674 FUN_60068674
//   600ce2c6 FUN_600ce2c6
//   600cc6f0 FUN_600cc6f0
//   60068470 FUN_60068470


/* src: thermal.cc */

void thermal__6005d3b4(int param_1)

{
  char *pcVar1;
  byte *pbVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  char *pcVar8;
  char local_2e;
  char local_2d;
  ushort local_2c [4];
  char local_23;
  
  if ((param_1 != 0) &&
     (uVar4 = timers__600cae18(*(undefined4 *)(param_1 + 4)),
     ((uVar4 % 1000) * 1000 + 500) / 1000 + (uVar4 / 1000) * 1000 != 10000)) {
    thunk_EXT_FUN_00007a2c(*(undefined4 *)(param_1 + 4),4,10000,0,10);
  }
  if (*(char *)(DAT_6005d5cc + 0x4362) == '\0') {
    cVar3 = '\t';
  }
  else {
    cVar3 = FUN_600d4330(DAT_6005d5d0,2,local_2c,200);
    if (cVar3 == '\0') {
      if ((*DAT_6005d5d4 <= local_2c[0]) || (local_2c[0] <= *DAT_6005d5d8)) {
        FUN_6010165c(0x28,DAT_6005d5e0,0xaf,DAT_6005d5dc,local_2c[0],*DAT_6005d5d8,*DAT_6005d5d4);
        cVar3 = FUN_6005d12c();
      }
    }
  }
  thermal__6005d160(cVar3,DAT_6005d5e8,DAT_6005d5e4);
  cVar3 = FUN_60068604(DAT_6005d5ec,local_2c);
  pcVar1 = DAT_6005d5f0;
  if (cVar3 == '\0') {
    if (*DAT_6005d5f0 != local_23) {
      if (local_23 == '\0') {
        FUN_6010165c(0x1e,DAT_6005d5e0,0x9f,DAT_6005d620);
        uVar7 = *DAT_6005d5f8;
      }
      else {
        FUN_6010165c(0x1e,DAT_6005d5e0,0x99,DAT_6005d5f4);
        cVar3 = FUN_60068470(DAT_6005d5ec,DAT_6005d5f8);
        if (cVar3 != '\0') goto LAB_6005d48e;
        uVar7 = 0x1004;
      }
      cVar3 = battery_charger_bq25601__600683f4(DAT_6005d5ec,uVar7);
      if (cVar3 == '\0') {
        cVar3 = '\0';
        *pcVar1 = local_23;
      }
    }
  }
LAB_6005d48e:
  thermal__6005d160(cVar3,DAT_6005d600,DAT_6005d5fc);
  pbVar2 = DAT_6005d604;
  local_2e = '\0';
  DataMemoryBarrier(0x1b);
  if ((-1 < (int)((uint)*DAT_6005d604 << 0x1f)) && (iVar5 = FUN_600cc8f8(DAT_6005d604), iVar5 != 0))
  {
    FUN_600d6dda(DAT_6005d608);
    FUN_600cc984(pbVar2);
  }
  iVar5 = FUN_600d6e14(0x2a);
  if (iVar5 == 0) {
    cVar3 = keys__60066070(0x2a,&local_2e,1);
  }
  else {
    cVar3 = FUN_600ce2c6(0x2a,&local_2e);
  }
  if (cVar3 == '\0') {
    if (local_2e == '\0') {
      cVar3 = FUN_60068674(DAT_6005d5ec,&local_2d);
      uVar6 = DAT_6005d630;
      pcVar1 = DAT_6005d624;
      if (cVar3 == '\0') {
        pcVar8 = DAT_6005d624 + -0x1a;
        iVar5 = 0;
        while( true ) {
          if (*pcVar1 != '\0') {
            cVar3 = FUN_600d4330(pcVar8,2,local_2c,200);
            if (cVar3 == '\0') {
              if ((local_2d != '\x05') || (local_2c[0] < 0xb43)) goto LAB_6005d4da;
              FUN_6010165c(0x28,DAT_6005d5e0,0x76,DAT_6005d62c);
              FUN_6006859c(DAT_6005d5ec,0);
              goto LAB_6005d582;
            }
          }
          iVar5 = iVar5 + 1;
          if (iVar5 == 3) break;
          FUN_6010165c(0x28,DAT_6005d5e0,0x6f,uVar6,iVar5,3);
          thunk_EXT_FUN_0000737c(100);
        }
        FUN_6010165c(0x28,DAT_6005d5e0,0x6a,DAT_6005d628);
LAB_6005d582:
        cVar3 = FUN_6005d12c();
      }
    }
    else {
LAB_6005d4da:
      cVar3 = '\0';
    }
  }
  pcVar1 = DAT_6005d60c;
  thermal__6005d160(cVar3,DAT_6005d614,DAT_6005d610);
  if ((*pcVar1 == '\0') && (uVar4 = FUN_600cc6f0(), uVar4 < 0x5000)) {
    *pcVar1 = '\x01';
    uVar6 = FUN_600cc6f0();
    FUN_6010165c(0x28,DAT_6005d5e0,0x89,DAT_6005d618,uVar6);
    trigger_bug_report__6005d714(DAT_6005d61c,0);
  }
  return;
}


