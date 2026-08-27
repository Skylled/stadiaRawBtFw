// 600482a8  FUN_600482a8  size=432 bytes
// --- callers ---
// --- callees ---
//   6004820c FUN_6004820c
//   60047aa8 tasks__60047aa8
//   6004c42c timers__600cad94
//   6004c084 thunk_FUN_601016a2
//   60047968 FUN_60047968
//   600488f4 heap_5_improved__600488f4
//   6004bc98 FUN_6004bc98
//   60048248 FUN_60048248
//   60047548 FUN_60047548
//   6004bb60 FUN_6004bb60
//   60047958 FUN_60047958


void FUN_600482a8(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  int iVar10;
  uint uVar11;
  uint local_38;
  code *local_34;
  int local_30;
  undefined4 uStack_2c;
  
  puVar5 = DAT_6004846c;
  uVar2 = DAT_6004845c;
  uVar1 = DAT_60048458;
  do {
    piVar3 = DAT_60048460;
    iVar10 = *(int *)*DAT_60048460;
    if (iVar10 == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = *(uint *)((int *)*DAT_60048460)[3];
    }
    FUN_60047958();
    uVar7 = FUN_60047968();
    puVar6 = DAT_60048470;
    puVar4 = DAT_60048464;
    if (uVar7 < *DAT_60048464) {
      timers__600cad94();
      *puVar4 = uVar7;
      tasks__60047aa8();
    }
    else {
      *DAT_60048464 = uVar7;
      if (iVar10 == 0) {
        bVar9 = *(int *)*DAT_60048468 == 0;
      }
      else {
        if (uVar11 <= uVar7) {
          tasks__60047aa8();
          iVar10 = *(int *)(*(int *)(*piVar3 + 0xc) + 0xc);
          FUN_6004bb60(iVar10 + 4);
          if ((*(int *)(iVar10 + 0x1c) == 1) &&
             (iVar8 = FUN_6004820c(iVar10,*(int *)(iVar10 + 0x18) + uVar11,uVar7,uVar11), iVar8 != 0
             )) {
            iVar8 = FUN_60048248(iVar10,0,uVar11,0,0);
            if (iVar8 == 0) {
              thunk_FUN_601016a2(uVar2,0x1e4,uVar1);
            }
          }
          (**(code **)(iVar10 + 0x24))(iVar10);
          goto LAB_600482f0;
        }
        bVar9 = false;
      }
      FUN_6004bc98(*puVar6,uVar11 - uVar7,bVar9);
      iVar10 = tasks__60047aa8();
      if (iVar10 == 0) {
        *puVar5 = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
    }
LAB_600482f0:
    while (iVar10 = FUN_60047548(*puVar6,&local_38,0), iVar10 != 0) {
      if ((int)local_38 < 0) {
        (*local_34)(local_30,uStack_2c);
      }
      iVar10 = local_30;
      if (-1 < (int)local_38) {
        if (*(int *)(local_30 + 0x14) != 0) {
          FUN_6004bb60(local_30 + 4);
        }
        uVar11 = FUN_60047968();
        if (uVar11 < *puVar4) {
          timers__600cad94();
        }
        *puVar4 = uVar11;
        if (local_38 < 10) {
          uVar7 = 1 << (local_38 & 0xff);
          if ((uVar7 & 0x210) == 0) {
            if ((uVar7 & 199) == 0) {
              if (((int)(uVar7 << 0x1a) < 0) && (*(char *)(iVar10 + 0x2c) == '\0')) {
                heap_5_improved__600488f4(iVar10);
              }
            }
            else {
              iVar8 = FUN_6004820c(iVar10,local_34 + *(int *)(iVar10 + 0x18),uVar11);
              if ((iVar8 != 0) &&
                 ((**(code **)(iVar10 + 0x24))(iVar10), *(int *)(iVar10 + 0x1c) == 1)) {
                iVar10 = FUN_60048248(iVar10,0,local_34 + *(int *)(iVar10 + 0x18),0,0);
                if (iVar10 == 0) {
                  thunk_FUN_601016a2(uVar2,0x2fd,uVar1);
                }
              }
            }
          }
          else {
            *(code **)(iVar10 + 0x18) = local_34;
            if (local_34 == (code *)0x0) {
              thunk_FUN_601016a2(uVar2,0x314,uVar1);
            }
            FUN_6004820c(iVar10,*(int *)(iVar10 + 0x18) + uVar11,uVar11,uVar11);
          }
        }
      }
    }
  } while( true );
}


