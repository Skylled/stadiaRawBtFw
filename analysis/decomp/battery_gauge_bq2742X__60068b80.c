// 60068b80  battery_gauge_bq2742X__60068b80  size=290 bytes
// src: battery_gauge_bq2742X.h
// --- callers ---
//   600d87c0 FUN_600d87c0
// --- callees ---
//   600d8518 FUN_600d8518
//   600d83e0 FUN_600d83e0
//   601016a2 FUN_601016a2
//   60068ae0 battery_gauge_bq2742X__60068ae0


/* src: battery_gauge_bq2742X.h */

void battery_gauge_bq2742X__60068b80(int param_1)

{
  ushort uVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  uint in_fpscr;
  float fVar5;
  float fVar6;
  undefined1 local_19;
  
  cVar2 = FUN_600d83e0(param_1,0x52,0,&local_19);
  if (cVar2 == '\0') {
    if (*(char *)(param_1 + 0x1b) == '\x01') {
      uVar3 = 10;
    }
    else {
      if (*(char *)(param_1 + 0x1b) != '\x02') {
        FUN_601016a2(DAT_60068ca8,0x95,DAT_60068ca4);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      uVar3 = 6;
    }
    uVar4 = (uint)*(ushort *)(*(int *)(param_1 + 8) + 4);
    uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 8);
    cVar2 = FUN_600d8518(param_1,uVar3,uVar4,&local_19);
    if (cVar2 == '\0') {
      if (*(char *)(param_1 + 0x1b) == '\x01') {
        uVar3 = 0xc;
      }
      else {
        if (*(char *)(param_1 + 0x1b) != '\x02') {
          FUN_601016a2(DAT_60068ca8,0x9e,DAT_60068ca4);
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        uVar3 = 8;
      }
      fVar6 = (float)VectorUnsignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
      uVar4 = VectorFloatToUnsigned(fVar6 * DAT_60068cac,3);
      cVar2 = FUN_600d8518(param_1,uVar3,uVar4 & 0xffff,&local_19);
      if (cVar2 == '\0') {
        if (*(char *)(param_1 + 0x1b) == '\x01') {
          uVar3 = 0x10;
        }
        else {
          if (*(char *)(param_1 + 0x1b) != '\x02') {
            FUN_601016a2(DAT_60068ca8,0xa7,DAT_60068ca4);
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          uVar3 = 10;
        }
        cVar2 = FUN_600d8518(param_1,uVar3,*(undefined2 *)(*(int *)(param_1 + 8) + 6),&local_19);
        if (cVar2 == '\0') {
          if (*(char *)(param_1 + 0x1b) == '\x01') {
            uVar3 = 0x1b;
          }
          else {
            if (*(char *)(param_1 + 0x1b) != '\x02') {
              FUN_601016a2(DAT_60068ca8,0xb0,DAT_60068ca4);
              do {
                    /* WARNING: Do nothing block with infinite loop */
              } while( true );
            }
            uVar3 = 0x15;
          }
          fVar5 = (float)VectorUnsignedToFloat((uint)uVar1,(byte)(in_fpscr >> 0x16) & 3);
          uVar4 = VectorFloatToUnsigned(fVar6 / (fVar5 * DAT_60068cb0),3);
          cVar2 = FUN_600d8518(param_1,uVar3,uVar4 & 0xffff,&local_19);
          if (cVar2 == '\0') {
            battery_gauge_bq2742X__60068ae0(param_1,local_19,0x52);
          }
        }
      }
    }
  }
  return;
}


