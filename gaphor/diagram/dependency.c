/*
 * Dependency
 *
 * This is LGPL'ed code.
 */

#include "dependency.h"
#include "common.h"
#include <diacanvas/dia-shape.h>
#include <diacanvas/dia-canvas-i18n.h>

static void dependency_class_init (RelationshipClass *klass);
static void dependency_init (Dependency *item);
static void dependency_dispose (GObject *object);
static void dependency_set_property (GObject *object,
					     guint property_id,
					     const GValue *value,
					     GParamSpec *pspec);
static void dependency_get_property (GObject *object,
					     guint property_id,
					     GValue *value,
					     GParamSpec *pspec);
static void dependency_update (DiaCanvasItem *item, gdouble affine[6]);
static gboolean dependency_connect (DiaCanvasItem *item, DiaHandle *handle);
static gboolean dependency_disconnect (DiaCanvasItem *item,
					   DiaHandle *handle);

static RelationshipClass *parent_class = NULL;

GType
dependency_get_type (void)
{
	static GType object_type = 0;

	if (!object_type) {
		static const GTypeInfo object_info = {
			sizeof (DependencyClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) dependency_class_init,
			(GClassFinalizeFunc) NULL,
			(gconstpointer) NULL, /* class_data */
			sizeof (Dependency),
			(guint16) 0, /* n_preallocs */
			(GInstanceInitFunc) dependency_init,
		};

		object_type = g_type_register_static (TYPE_RELATIONSHIP,
						      "Dependency",
						      &object_info, 0);
	}

	return object_type;
}


static void
dependency_class_init (RelationshipClass *klass)
{
	GObjectClass *object_class;
	DiaCanvasItemClass *item_class;
	
	object_class = (GObjectClass*) klass;
	item_class = DIA_CANVAS_ITEM_CLASS (klass);
	
	parent_class = g_type_class_peek_parent (klass);

	object_class->dispose = dependency_dispose;
	object_class->get_property = dependency_get_property;
	object_class->set_property = dependency_set_property;
	
	item_class->update = dependency_update;

	klass->subject_class = "Dependency";
	klass->head_name = "supplier";
	klass->tail_name = "client";
	klass->head_xname = "supplierDependency";
	klass->tail_xname = "clientDependency";
}


static void
dependency_init (Dependency *item)
{
	gdouble *dash;
	DiaCanvasLine *line = (DiaCanvasLine*) item;

	line->has_head = TRUE;
	line->head_a = 0.5;
	line->head_b = 15.0;
	line->head_c = 10.0;
	line->head_d = 10.0;
	line->head_fill_color = 0;

	dash = g_new (gdouble, 2);
	dash[0] = 7.0;
	dash[1] = 5.0;
	DIA_CANVAS_LINE(item)->n_dash = 2;
	DIA_CANVAS_LINE(item)->dash = dash;
}


static void
dependency_set_property (GObject *object, guint property_id,
				 const GValue *value, GParamSpec *pspec)
{
	PyObject *pyobj;

	switch (property_id) {
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
dependency_get_property (GObject *object, guint property_id,
				 GValue *value, GParamSpec *pspec)
{
	PyObject *pyobj;

	switch (property_id) {
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
dependency_dispose (GObject *object)
{
	G_OBJECT_CLASS (parent_class)->dispose (object);
}


static void
dependency_update (DiaCanvasItem *item, gdouble affine[6])
{
	DIA_CANVAS_ITEM_CLASS (parent_class)->update (item, affine);
}

